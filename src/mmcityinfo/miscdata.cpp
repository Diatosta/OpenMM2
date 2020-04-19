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

#include "miscdata.h"

mmMiscData::mmMiscData()
{
    stub<member_func_t<void, mmMiscData>>(0x524A30, this);
}

int mmMiscData::Open(char* a2)
{
    return stub<member_func_t<int, mmMiscData, char*>>(0x524B20, this, a2);
}

int mmMiscData::Close()
{
    return stub<member_func_t<int, mmMiscData>>(0x524C90, this);
}
