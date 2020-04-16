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

#include "vehlist.h"

#include "data/asset.h"
#include <core\output.h>

mmVehList::mmVehList()
{
    stub<member_func_t<void, mmVehList>>(0x524550, this);
}

mmVehInfo* mmVehList::GetVehicleInfo(char* a2)
{
    return stub<member_func_t<mmVehInfo*, mmVehList, char*>>(0x524610, this, a2);
}

void mmVehList::SetDefaultVehicle(char* a2)
{
    stub<member_func_t<void, mmVehList, char*>>(0x524690, this, a2);
}

void mmVehList::Load(char* a1)
{
    stub<member_func_t<void, mmVehList, char*>>(0x524720, this, a1);
}

void mmVehList::LoadAll()
{
    stub<member_func_t<void, mmVehList>>(0x524950, this);
}
