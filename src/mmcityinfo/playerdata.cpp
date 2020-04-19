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

#include "playerdata.h"

int mmPlayerData::OpenCityRecord(char* a2)
{
    return stub<member_func_t<int, mmPlayerData, char*>>(0x5271B0, this, a2);
}

int mmPlayerData::CloseCityRecord()
{
    return stub<member_func_t<int, mmPlayerData>>(0x527220, this);
}

void mmPlayerData::SetTagID(float a2)
{
    stub<member_func_t<void, mmPlayerData, float>>(0x527260, this, a2);
}

void mmPlayerData::Reset()
{
    stub<member_func_t<void, mmPlayerData>>(0x527BB0, this);
}

void mmPlayerData::SetCity(char* a2)
{
    stub<member_func_t<void, mmPlayerData, char*>>(0x527C30, this, a2);
}

void mmPlayerData::SetName(char* a2)
{
    stub<member_func_t<void, mmPlayerData, char*>>(0x527C80, this, a2);
}

char* mmPlayerData::GetName()
{
    return stub<member_func_t<char*, mmPlayerData>>(0x527CC0, this);
}

void mmPlayerData::SetNetName(char* a2)
{
    stub<member_func_t<void, mmPlayerData, char*>>(0x527CD0, this, a2);
}

void mmPlayerData::SetFileName(char* a2)
{
    stub<member_func_t<void, mmPlayerData, char*>>(0x527D20, this, a2);
}

char* mmPlayerData::GetFileName()
{
    return stub<member_func_t<char*, mmPlayerData>>(0x527D60, this);
}

int mmPlayerData::Save(char* a2, int a3)
{
    return stub<member_func_t<int, mmPlayerData, char*, int>>(0x527DA0, this, a2, a3);
}
