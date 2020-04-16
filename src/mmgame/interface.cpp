/*
    OpenMM2 - An Open Source Re-Implementation of Midtown Madness 2
    Copyright (C) 2019 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "interface.h"

#include "mmwidget/manager.h"
#include "mmnetwork/network.h"
#include "mmcityinfo/state.h"
#include "mmcityinfo/playerdir.h"
#include "mmcityinfo/citylist.h"
#include "mmcityinfo/vehlist.h"
#include "mmui/netarena.h"
#include "mmui/main.h"
#include "mmui/about.h"
#include "mmui/vehicle.h"
#include "mmui/vshow.h"
#include "mmui/race.h"
#include "mmui/netselect.h"
#include "mmui/crash.h"
#include "mmui/ccintro.h"
#include "mmui/options.h"
#include "mmui/graphics.h"
#include "mmui/racehost.h"
#include "mmui/dlg_tcpip.h"
#include "mmui/dlg_ctrl.h"
#include "mmui/dlg_serial.h"
#include "mmui/dlg_newp.h"
#include "mmui/dlg_drec.h"
#include "mmui/dlg_renv.h"
#include "mmui/dlg_password.h"
#include "mmui/dlg_host.h"
#include "mmui/dlg_replay.h"
#include "mmui/dlg_redit.h"
#include "mmui/dlg_city2.h"
#include "data/callback.h"
#include "gfx/d3dpipe.h"
#include "level/progress.h"
#include "localize/localize.h"
#include "node/root.h"

void __cdecl GetHostCars(string* a1)
{
    stub<cdecl_t<void, string*>>(0x407B80, a1);
}

mmInterface::mmInterface()
    : asNode()
{
    LocString* v4;
    mmVehList* v6;
    mmCityList* v8;
    char* v9;
    unsigned int v10;
    char v11;
    char* v12;
    const char* v13;
    int v14;
    int v181;
    const char* v182;
    datCallback* v185;

    pPlayerDirectoryE4 = new mmPlayerDirectory();
    pPlayerConfig1C8 = new mmPlayerConfig();
    pMiscData7340 = new mmMiscData();
    pMiscData74E4 = new mmMiscData();
    string7740 = new string();
    string7748 = new string();
    gfxLostCallback = nullptr;

    lvlProgress::BeginTask("interface");
    lvlProgress::UpdateTask(20.0, false);

    MENUMGR = new MenuManager();

    v4 = AngelReadString(0x40u);

    v6 = new mmVehList();
    v6->LoadAll();

    v8 = new mmCityList();
    v8->LoadAll();
    v9 = (char*)v8->GetCurrentCity();
    v9 += 84;

    v10 = strlen(v9) + 1;
    v11 = v10;
    v10 >>= 2;
    memcpy(MMSTATE.CityLocale, v9, 4 * v10);

    v13 = &v9[4 * v10];
    v12 = &MMSTATE.CityLocale[4 * v10];
    v14 = v11 & 3;
    memcpy(v12, v13, v14);

    ROOT.AddChild(MENUMGR);
    MENUMGR->AllocateMenuSwitchAudio();
    MENUMGR->Init(64, 1, "bgframe");
    MENUMGR->DisableNavBar();

    lvlProgress::UpdateTask(30.0, false);

    pMainMenu = new MainMenu(1);
    pAboutMenu = new AboutMenu(34);
    pVehicle = new Vehicle(8);

    lvlProgress::UpdateTask(35.0, false);

    pVehShowcase = new VehShowcase(9);
    pRaceMenu = new RaceMenu(7);
    pNetSelectMenu = new NetSelectMenu(10);
    pCrashCourse = new class CrashCourse(39);
    pCrashCourseIntro = new CrashCourseIntro(40);
    pOptionsMenu = new OptionsMenu(2);
    pGraphicsOptions = new GraphicsOptions(4);
    pAudioOptions = new AudioOptions(3);
    pControlCustom = new ControlCustom(41);
    pControlSetup = new ControlSetup(5);

    pControlSetup->dword722C = pControlCustom->dword7210;

    lvlProgress::UpdateTask(50.0, false);

    pHostRaceMenu = new HostRaceMenu(11);
    pNetArena = new NetArena(12);

    lvlProgress::UpdateTask(55.0, false);

    pDialog_TCPIP = new Dialog_TCPIP(
        14, 0.5, 0.2, 200.0 / (float)gfxPipeline::m_iHeight, 200.0 / (float)gfxPipeline::m_iWidth, "tcp_dlg");
    pDialog_ControlAssign = new Dialog_ControlAssign(
        21, 0.5, 0.2, 300.0 / (float)gfxPipeline::m_iHeight, 100.0 / (float)gfxPipeline::m_iWidth, "ctrl_dlg");
    pDialog_Serial = new Dialog_Serial(
        16, 0.5, 0.1, 0.0 / (float)gfxPipeline::m_iHeight, 330.0 / (float)gfxPipeline::m_iWidth, "srl_dlg");

    lvlProgress::UpdateTask(60.0, false);

    pDialog_NewPlayer = new Dialog_NewPlayer(
        17, 0.3, 0.1, 0.0 / (float) gfxPipeline::m_iHeight, 330.0 / (float) gfxPipeline::m_iWidth, "newp_dlg");
    pDialog_MessageC4 = new Dialog_Message(
        18, 0.3, 0.1, 300.0 / (float) gfxPipeline::m_iHeight, 330.0 / (float) gfxPipeline::m_iWidth, "rtrv_dlg");
    pDialog_MessageC4->Init(100, "dlg_can", 0);

    lvlProgress::UpdateTask(65.0, false);

    pDialog_DriverRec = new Dialog_Message(
        19, 0.3, 0.1, 300.0 / (float) gfxPipeline::m_iHeight, 400.0 / (float) gfxPipeline::m_iWidth, "drec_dlg");
    pDialog_HallOfFame = new Dialog_HallOfFame(
        20, 0.1, 0.1, 540.0 / (float) gfxPipeline::m_iHeight, 460.0 / (float) gfxPipeline::m_iWidth, "hoff_dlg");
    pDialog_HallOfFame->InitRaceRecord();

    lvlProgress::UpdateTask(70.0, false);

    pDialog_MessageB4 = new Dialog_Message(
        23, 0.3, 0.3, 0.625, 0.1583, "lock_dlg");
    pDialog_MessageB4->Init(100, "dlg_ok", 0);

    pDialog_MessageB8 = new Dialog_Message(
        24, 0.3, 0.1, 300.0 / (float) gfxPipeline::m_iHeight, 150.0 / (float) gfxPipeline::m_iWidth, "badp_dlg");
    pDialog_MessageB8->Init(100, "dlg_ok", 0);

    pDialog_RaceEnvironment = new Dialog_RaceEnvironment(
        22, 0.2, 0.2, 300.0 / (float) gfxPipeline::m_iHeight, 330.0 / (float) gfxPipeline::m_iWidth, "renv_dlg");

    lvlProgress::UpdateTask(75.0, false);

    pDialog_Password = new Dialog_Password(
        25, 0.3, 0.1, 300.0 / (float) gfxPipeline::m_iHeight, 150.0 / (float) gfxPipeline::m_iWidth, "pass_dlg");
    pDialog_Host = new Dialog_Host(
        36, 0.3, 0.1, 300.0 / (float) gfxPipeline::m_iHeight, 150.0 / (float) gfxPipeline::m_iWidth, "host_dlg");

    lvlProgress::UpdateTask(80.0, false);

    pDialog_Replay = new Dialog_Replay(
        37, 0.3, 0.3, 0.625, 0.1583, "rpl_bk");

    pDialog_MessageBC = new Dialog_Message(27, 0.3, 0.3, 0.625, 0.1583, "quit_dlg");
    pDialog_MessageBC->Init(101, "dlg_ok", "dlg_can");

    pDialog_MessageC0 = new Dialog_Message(28, 0.3, 0.3, 0.625, 0.1583, "delp_dlg");
    pDialog_MessageC0->Init(101, "dlg_yes", "dlg_no");

    pDialog_MessageC8 = new Dialog_Message(29, 0.3, 0.3, 0.46875, 0.46875, "dupp_dlg");
    pDialog_MessageC8->Init(100, "dlg_ok", 0);

    pDialog_MessageD8 = new Dialog_Message(32, 0.3, 0.3, 0.46875, 0.46875, "xasn_dlg");
    pDialog_MessageD8->Init(100, "dlg_ok", 0);

    lvlProgress::UpdateTask(85.0, false);

    pDialog_MessageDC = new Dialog_Message(33, 0.3, 0.3, 0.46875, 0.46875, "plim_dlg");
    pDialog_MessageDC->Init(100, "dlg_ok", 0);

    pDialog_MessageCC = new Dialog_Message(30, 0.3, 0.3, 0.625, 0.1583, "lstp_dlg");
    pDialog_MessageCC->Init(100, "dlg_ok", 0);

    pDialog_MessageD4 = new Dialog_Message(26, 0.3, 0.3, 0.625, 0.1583, "zone_dlg");
    pDialog_MessageD4->Init(100, "dlg_can", 0);

    pDialog_MessageD0 = new Dialog_Message(31, 0.3, 0.3, 0.46875, 0.46875, "odef_dlg");
    pDialog_MessageD0->Init(101, "dlg_ok", "dlg_can");

    pDialog_ReplayEdit = new Dialog_ReplayEdit(
        38, 0.3, 0.1, 300.0 / (float) gfxPipeline::m_iHeight, 150.0 / (float) gfxPipeline::m_iWidth, "redit_bk");

    pDialog_City2 = new Dialog_City2(35, 0.3, 0.3, 0.625, 0.1583, "cenv_dlg");
    pDialog_Eject = new Dialog_Eject(42, 0.3, 0.3, 0.625, 0.1583, "ejct_dlg");

    pDialog_MessageE0 = new Dialog_Message(43, 0.3, 0.3, 0.625, 0.1583, "boot_dlg");
    pDialog_MessageE0->Init(100, "dlg_ok", 0);

    lvlProgress::UpdateTask(90.0, false);

    pHostRaceMenu->AssignBackground("host_bk");
    pNetSelectMenu->AssignBackground("sess_bk");
    pNetArena->AssignBackground("lobbh_bk");
    pRaceMenu->AssignBackground("race_bk");
    pVehicle->AssignBackground("veh_bk");
    pGraphicsOptions->AssignBackground("gfx_bk");
    pCrashCourse->AssignBackground("ccsf_bk");
    pCrashCourseIntro->AssignBackground("ilon_bk");
    pControlSetup->AssignBackground("ctrl_bk");
    pAudioOptions->AssignBackground("aud_bk");
    pMainMenu->AssignBackground("main_bk");
    pAboutMenu->AssignBackground("about_bk");
    pOptionsMenu->AssignBackground("opt_bk");
    pControlCustom->AssignBackground("cuss_bk");

    lvlProgress::UpdateTask(95.0, false);

    pHostRaceMenu->dword78 = 10;
    pNetSelectMenu->dword78 = 1;
    pNetArena->dword78 = 10;
    pRaceMenu->dword78 = 1;
    pVehicle->dword78 = 7;
    pControlSetup->dword78 = 2;
    pGraphicsOptions->dword78 = 2;
    pAudioOptions->dword78 = 2;
    pVehShowcase->dword78 = 8;
    pCrashCourse->dword78 = 40;
    pCrashCourseIntro->dword78 = 1;

    //v185 = new datCallback(&mmInterface::PlayerLoadCB);

    // TODO: initialize datCallbacks

    //pDialog_Eject->SetBootCB();

    dword76AC = 0;

    //InitPlayerInfo();

    lvlProgress::UpdateTask(97.0, false);

    v181 = pAudioOptions->FindDevice(MMSTATE.AudioDeviceName);

    lvlProgress::UpdateTask(99.0, false);

    if (v181 == -1)
    {
        v182 = pAudioOptions->GetCurrentDeviceName();

        if (v182)
        {
            strcpy(MMSTATE.AudioDeviceName, v182);
        }
    }
    else
    {
        pAudioOptions->SetDevice(v181);
    }

    pAudioOptions->ResetMusic();
    pAudioOptions->ResetSoundFX();
    pAudioOptions->ResetSoundQuality();
    pAudioOptions->ResetStereo();
    pAudioOptions->ResetCommentary();

    lvlProgress::UpdateTask(100.0, false);

    PlayUIMusic();
    InitLobby();

    dword7688 = 0;
    dword768C = 0;
    dword7690 = 0;
    dword78 = 0;
    dword7C = 0;
    dword80 = 0;

    if (strlen(MMSTATE.VehicleName) == 0)
    {
        strcpy(MMSTATE.VehicleName, (const char*)(VehicleList->GetVehicleInfo(0) + 4));
        MMSTATE.VehiclePaintjob = 0;
        pVehicle->AllSetCar(MMSTATE.VehicleName, 0);
    }

    MMSTATE.ReplayName[0] = 0;
    MMSTATE.IsHost = false;
    GetHostCars(string7740);

    if (!strcmp("london", (const char*)CityList->GetCurrentCity() + 84))
    {
        pCrashCourse->AssignBackground("cclon_bk");
    }

    MMSTATE.NetStartArray.Clear();
    bool_627374 = false;

    gfxLostCallback = sub_409010;

    // TODO: a missing callbac



    lvlProgress::EndTask();

    Displayf("End of mmInterface");

    //stub<member_func_t<void, mmInterface>>(0x407C80, this);
}

void mmInterface::InitPlayerInfo()
{
    stub<member_func_t<void, mmInterface>>(0x409030, this);
}

mmInterface::~mmInterface()
{
    stub<member_func_t<void, mmInterface>>(0x4094C0, this);
}

void mmInterface::MessageCallback(void* a2, void* a3)
{
    stub<member_func_t<void, mmInterface, void*, void*>>(0x4095E0, this, a2, a3);
}

void mmInterface::MessageCallback2(void* a2, void* a3)
{
    stub<member_func_t<void, mmInterface, void*, void*>>(0x409D30, this, a2, a3);
}

void mmInterface::Switch(int a2, int a3)
{
    stub<member_func_t<void, mmInterface, int, int>>(0x40CF90, this, a2, a3);
}

void mmInterface::LobbySwitch(int a2, int a3)
{
    stub<member_func_t<void, mmInterface, int, int>>(0x40D460, this, a2, a3);
}

void mmInterface::GetUnlockedCar()
{
    strcpy(MMSTATE.VehicleName, "vpbug");
}

void mmInterface::GetUnlockedColor()
{
    MMSTATE.VehiclePaintjob = 0;
}

void mmInterface::ShowMain(int firstLoad)
{
    int vehiclePaintjob;

    MENUMGR->SetDefaultBackgroundImage("bgframe");
    MENUMGR->AddPointer();

    MENUMGR->EnableNavBar();

    if (!firstLoad)
    {
        MENUMGR->Enable(1);
        MENUMGR->SetFocus(this->pMainMenu);

        if (!NETMGR.InLobby)
        {
            return;
        }

        if (MMSTATE.GameMode == dgGameMode::CrashCourse)
        {
            MMSTATE.GameMode = dgGameMode::Cruise;
        }

        this->LobbyCreate();
        this->pNetArena->SetHost(NETMGR.IsHost);

        if (NETMGR.IsHost)
        {
            this->LobbySwitch(12, 0);
            MMSTATE.unk_EC = 2;
            return;
        }

        if (MMSTATE.IsHost)
        {
            this->SendMsg(522, 1);
            MENUMGR->OpenDialog(18);
            MMSTATE.unk_EC = 2;
            return;
        }

        this->JoinLobbyGame();
        MMSTATE.unk_EC = 2;
        return;
    }

    if (NETMGR.InLobby)
    {
        if ((VehicleList->GetVehicleInfo(MMSTATE.VehicleName) + 244))
        {
            this->GetUnlockedCar();
        }
        else
        {
            vehiclePaintjob = MMSTATE.VehiclePaintjob;
            int v1 = *(int*)(VehicleList->GetVehicleInfo(MMSTATE.VehicleName) + 264);

            if ((1 << vehiclePaintjob) & v1)
            {
                this->GetUnlockedColor();
            }
        }
        this->pNetArena->SetHost(NETMGR.IsHost);
        this->RefreshMe();

        if (NETMGR.IsHost)
        {
            this->LobbySwitch(12, 0);
            MMSTATE.unk_EC = 2;
            return;
        }

        if (MMSTATE.IsHost)
        {
            MENUMGR->Enable(1);
            MENUMGR->SetFocus(this->pMainMenu);
            this->SendMsg(522, 1);
            MENUMGR->OpenDialog(18);
            MMSTATE.unk_EC = 2;
            return;
        }

        this->JoinLobbyGame();
        MMSTATE.unk_EC = 2;
        return;
    }

    if (GraphicsChange)
    {
        this->PlayerSetState();
        MENUMGR->Enable(2);
        MENUMGR->SetFocus(this->pOptionsMenu);
        this->pOptionsMenu->dword78 = GraphicsPreviousMenu;
        GraphicsChange = 0;
    }
    else if (MMSTATE.unk_EC == 1)
    {
        if (NETMGR.SessionOpen)
        {
            if (MMSTATE.GameMode == dgGameMode::CrashCourse)
            {
                MMSTATE.GameMode = dgGameMode::Cruise;
            }

            MENUMGR->Enable(12);
            MENUMGR->SetFocus((UIMenu*) this->pNetArena);
            this->pNetArena->dword78 = 10;
            this->pNetArena->SetHost(NETMGR.IsHost);
            this->dword78 = NETMGR.IsHost;
            this->pNetArena->SetMyStatus(this->dword78);
            this->Switch(12, 1);
            this->RefreshMe();
            // TODO: Implement the missing datCallbacks
            /*datCallback(this, &mmInterface::MessageCallback);
            NETMGR.SysMessageCB = datCallback(this->MessageCallback, (void*)0);
            NETMGR.AppMessageCB = datCallback(this->MessageCallback2, (void*)0);*/
        }
        else
        {
            MENUMGR->Enable(1);
            MENUMGR->SetFocus(this->pMainMenu);
            this->Switch(10, 1);
        }
    }
    else if (MMSTATE.InCrashCourse)
    {
        MENUMGR->Enable(39);
        MENUMGR->SetFocus(this->pAboutMenu);
    }
    else
    {
        MENUMGR->Enable(7);
        MENUMGR->SetFocus(this->pRaceMenu);
    }
}

void mmInterface::PlayerLoadCB()
{
    stub<member_func_t<void, mmInterface>>(0x40DF30, this);
}

void mmInterface::JoinLobbyGame()
{
    this->LobbySwitch(12, 0);
    this->pNetArena->SetHost(0);
}

void mmInterface::PlayerSetState()
{
    stub<member_func_t<void, mmInterface>>(0x40E150, this);
}

void mmInterface::InitLobby()
{
    stub<member_func_t<void, mmInterface>>(0x410090, this);
}

int mmInterface::LobbyCreate()
{
    return stub<member_func_t<int, mmInterface>>(0x411A10, this);
}

void mmInterface::SendMsg(int a1, int a2)
{
    NETMGR.Send(0, a1, 0, 0, a2);
}

void mmInterface::RefreshMe()
{
    stub<member_func_t<void, mmInterface>>(0x412340, this);
}

void mmInterface::PlayUIMusic()
{
    stub<member_func_t<void, mmInterface>>(0x412280, this);
}
