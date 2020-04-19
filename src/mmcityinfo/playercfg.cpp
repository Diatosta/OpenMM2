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

#include "playercfg.h"

mmPlayerConfig::mmPlayerConfig()
{
    stub<member_func_t<void, mmPlayerConfig>>(0x5254B0, this);
}

int mmPlayerConfig::Load(char* a2)
{
    return stub<member_func_t<int, mmPlayerConfig, char*>>(0x525750, this, a2);
}

int mmPlayerConfig::Save(char* a2, int a3)
{
    return stub<member_func_t<int, mmPlayerConfig, char*, int>>(0x525C80, this, a2, a3);
}

void mmPlayerConfig::DefaultViewSettings()
{
    stub<member_func_t<void, mmPlayerConfig>>(0x526350, this);
}
