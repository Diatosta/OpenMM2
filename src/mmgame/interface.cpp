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
#include "mmui/netarena.h"
#include "mmcityinfo/vehlist.h"
#include "data/callback.h"

mmInterface::mmInterface()
{
    stub<member_func_t<void, mmInterface>>(0x407C80, this);
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
    datCallback* v6, *v11;
    datCallback v14;

    MENUMGR->SetDefaultBackgroundImage("bgframe");
    MENUMGR->AddPointer();

    MENUMGR->EnableNavBar();

    if (!firstLoad)
    {
        MENUMGR->Enable(1);
        MENUMGR->SetFocus(this->dword18);

        if (!NETMGR.InLobby)
        {
            return;
        }

        if (MMSTATE.GameMode == dgGameMode::CrashCourse)
        {
            MMSTATE.GameMode = dgGameMode::Cruise;
        }

        this->LobbyCreate();
        this->dword54->SetHost(NETMGR.IsHost);

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
        if ((VehicleList.GetVehicleInfo(MMSTATE.VehicleName) + 244))
        {
            this->GetUnlockedCar();
        }
        else
        {
            vehiclePaintjob = MMSTATE.VehiclePaintjob;
            int v1 = *(int*)(VehicleList.GetVehicleInfo(MMSTATE.VehicleName) + 264);

            if ((1 << vehiclePaintjob) & v1)
            {
                this->GetUnlockedColor();
            }
        }
        this->dword54->SetHost(NETMGR.IsHost);
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
            MENUMGR->SetFocus(this->dword18);
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
        MENUMGR->SetFocus(this->dword3C);
        this->dword3C->dword78 = GraphicsPreviousMenu;
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
            MENUMGR->SetFocus((UIMenu*) this->dword54);
            this->dword54->dword78 = 10;
            this->dword54->SetHost(NETMGR.IsHost);
            this->dword78 = NETMGR.IsHost;
            this->dword54->SetMyStatus(this->dword78);
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
            MENUMGR->SetFocus(this->dword18);
            this->Switch(10, 1);
        }
    }
    else if (MMSTATE.InCrashCourse)
    {
        MENUMGR->Enable(39);
        MENUMGR->SetFocus(this->dword34);
    }
    else
    {
        MENUMGR->Enable(7);
        MENUMGR->SetFocus(this->dword1C);
    }
}

void mmInterface::JoinLobbyGame()
{
    this->LobbySwitch(12, 0);
    this->dword54->SetHost(0);
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

void mmInterface::RefreshMe(void)
{
    stub<member_func_t<void, mmInterface>>(0x412340, this);
}
