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

#include "citylist.h"

#include "data/asset.h"

mmCityList::mmCityList()
{
    stub<member_func_t<void, mmCityList>>(0x524160, this);
}

mmCityList::~mmCityList()
{
    stub<member_func_t<void, mmCityList>>(0x524180, this);
}

mmCityInfo* mmCityList::GetCityInfo(char* a2)
{
    return stub<member_func_t<mmCityInfo*, mmCityList, char*>>(0x524220, this, a2);
}

void mmCityList::SetCurrentCity(char* a2)
{
    stub<member_func_t<void, mmCityList, char*>>(0x5242C0, this, a2);
}

mmCityInfo* mmCityList::GetCurrentCity()
{
    return stub<member_func_t<mmCityInfo*, mmCityList>>(0x524320, this);
}

void mmCityList::Load(char* a2)
{
    stub<member_func_t<void, mmCityList, char*>>(0x524330, this, a2);
}

void mmCityList::LoadAll()
{
    stub<member_func_t<void, mmCityList>>(0x5244F0, this);
}
