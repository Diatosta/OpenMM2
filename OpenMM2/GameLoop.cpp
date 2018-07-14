#include "stdafx.h"
#include "GameLoop.h"

#include "gfxBitmap.h"
#include "gfxImage.h"
#include "Main.h"

#include "datTimeManager.h"

#include "gfxPipeline.h"
#include "asRoot.h"

#include "mmReplayManager.h"
#include "mmInterface.h"

#include "memMemoryAllocator.h"
#include "mmCDPlayer.h"
#include "AudioOptions.h"
#include "AudManager.h"
#include "mmPlayer.h"
#include "mmGameManager.h"
#include "asNetwork.h"
#include "gfxInterface.h"

#include "vgl.h"

#include "mmStatePack.h"
#include "Font.h"

#include "eqEventHandler.h"
#include "asCullManager.h"
#include "mmInput.h"

#include "gfxTexture.h"

#include "localize.h"

instvar(0x5E0CE0, gfxBitmap*, LoadingBitmap);
instvar(0x5E0CF8, bool, NeedStartup);

void GetLoadScreenName(char *buffer)
{
    char gameModeBuffer[20]; // [sp+8h] [bp-14h]@3

    if (gameState)
    {
        sprintf_s(buffer, 80, "%s_", MMSTATE.CityName);
        sprintf_s(gameModeBuffer, dgGameModeNames[MMSTATE.GameMode], MMSTATE.RaceId);
        strcat_s(buffer, 80, gameModeBuffer);
    }
    else
    {
        strcpy_s(buffer, 80, "splash");
    }
}

void BeginPhase(bool splashScreen)
{
    datDisplayUsed("Start of BeginPhase");

    if (NeedStartup)
    {
        InitDirectDraw();

        NeedStartup = false;
    }

    datDisplayUsed("Just before CreateBankManager");

    int width = 640;
    int height = 480;
    int depth = 16;

    if (!splashScreen)
    {
        auto currentRes = gfxInterface::Current()->CurrentResolution();

        width = currentRes->ScreenWidth;
        height = currentRes->ScreenHeight;
        depth = currentRes->ColorDepth;
    }

    gfxPipeline::SetRes(width, height, depth, depth, 0);

    gfxPipeline::BeginGfx3D();

    vglSetFormat(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1, 0, 0, 0);

    datDisplayUsed("Just before loading screen");

    char loadingScreenName[80];

    GetLoadScreenName(loadingScreenName);

    gfxImage* loadingImage = gfxLoadImage(loadingScreenName, 0);

    if (!loadingImage)
    {
        loadingImage = gfxLoadImage("loading", 0);
        if (!loadingImage)
        {
            MessageBoxA(0, LANG_STRING(0x263u), APPTITLE, 0x10u);

            exit(0);
        }
    }

    loadingImage->Scale(width, height);

    lpLoadingBitmap = gfxBitmap::Create(loadingImage, 0);

    loadingImage->Release();

    ProgressCB("", 10);
    datDisplayUsed("Just after loading screen");

    gfxReleaseFont();

    gfxTexture::EnableCache(0);

    gfxCreateFont();

    eqEventHandler* eventHandler = new eqEventHandler();
    eqEventHandler::SuperQ = eventHandler;

    datDisplayUsed("Just before InitAudioManager");

    InitAudioManager(audioFlags & 1);

    datDisplayUsed("Just after InitAudioManager");

    ROOT.AddChild(MMAUDMGRPTR);

    asCullManager* cullManager = new asCullManager(512, 64);

    (void)cullManager;

    datDisplayUsed("Just before GameInput");

    mmInput* input = new mmInput();

    (void)input;

    GameInputPtr->AttachToPipe();
    GameInputPtr->Init(MMSTATE.InputDevice);

    datDisplayUsed("At end of BeginPhase");

    // return stub<cdecl_t<void, bool>>(0x401AA0, splashScreen);
}

void EndPhase(void)
{
    return stub<cdecl_t<void>>(0x401FC0);
}

void RestoreFocus(void)
{
    uint16_t width = LoadingBitmap->Width;
    uint16_t height = LoadingBitmap->Height;

    RECT position =
    {
        0, 0, width, height
    };

    lpdsFront->BltFast(
        (gfxPipeline::m_iWidth - width) / 2,
        (gfxPipeline::m_iHeight - height) / 2,
        LoadingBitmap->Surface,
        &position,
        DDBLTFAST_WAIT);

    if (mmGameManager::Instance && !ROOT.IsPaused() && !NETMGR.SessionOpen)
    {
        mmGameManager::Instance->ForcePopupUI();
    }
}

void GameLoop(bool update)
{
    return stub<cdecl_t<void, bool>>(0x401A00, update);
}

void MainPhase(bool parsedStateArgs, int firstLoad)
{
    BeginPhase(gameState == 0);

    datTimeManager::RealTime(0.0);

    ROOT.ResChange(gfxPipeline::m_iWidth, gfxPipeline::m_iHeight);

    if (ROOT.IsPaused())
    {
        ROOT.SetPause(0);
    }

    gfxImage* imgReloading = gfxLoadImage("reloading", 0);

    if (imgReloading)
    {
        LoadingBitmap = gfxBitmap::Create(imgReloading, false);

        imgReloading->Release();

        if (LoadingBitmap)
        {
            gfxRestoreCallback = RestoreFocus;
        }
    }
    else
    {
        LoadingBitmap = 0;
    }

    EnableTextureVariantHandler = gameState == 1;

    mmReplayManager* replayManager = nullptr;
    mmInterface* uiInterface = nullptr;
    mmGameManager* gameManager = nullptr;

    switch (gameState)
    {
        case 0:
        {
            mmReplayManager::ReplayName[0] = '\0';

            replayManager = new mmReplayManager();
            uiInterface = new mmInterface();

            ROOT.AddChild(uiInterface);

            uiInterface->Reset();
            uiInterface->ShowMain(firstLoad);

            parsedStateArgs = 1;
        } break;

        case 1:
        {
            if (hasMusicCD && audioFlags & 4)
            {
                MMAUDMGRPTR->EnableCD();
                MMAUDMGRPTR->PlayCDTrack(2, 1);
            }

            datDisplayUsed("Before mmReplayManager");

            replayManager = new mmReplayManager();

            if (mmReplayManager::ReplayName[0])
            {
                replayManager->LoadReplay(mmReplayManager::ReplayName);
            }

            datDisplayUsed("Before mmGameManager");

            gameManager = new mmGameManager();

            replayManager->AddChild(gameManager);

            ROOT.AddChild(replayManager);

            replayManager->Player = PLAYER;

            if (mmReplayManager::ReplayName[0])
            {
                gameManager->ForceReplayUI();
            }

            parsedStateArgs = 0;
        } break;
    }

    lpLoadingBitmap->Release();
    lpLoadingBitmap = 0;

    SetFocus(hwndMain);
    gameState = -1;
    datDisplayUsed("Just before GameLoop");

    GameLoop(parsedStateArgs);

    if (uiInterface)
    {
        ROOT.RemoveChild(uiInterface);

        delete uiInterface;
    }

    if (replayManager)
    {
        ROOT.RemoveChild(replayManager);

        delete replayManager;
    }

    if (gameManager)
    {
        delete gameManager;
    }

    if (LoadingBitmap)
    {
        LoadingBitmap = 0;
        gfxRestoreCallback = 0;
    }

    EndPhase();
}