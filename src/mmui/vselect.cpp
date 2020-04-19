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

#include "vselect.h"

VehicleSelectBase::VehicleSelectBase(int a2)
{
    stub<member_func_t<void, VehicleSelectBase, int>>(0x4F5470, this, a2);
}

void VehicleSelectBase::InitCarSelection(int a2, float a3, float a4, float a5, float a6)
{
    stub<member_func_t<void, VehicleSelectBase, int, float, float, float, float>>(0x4F57C0, this, a2, a3, a4, a5, a6);
}

void VehicleSelectBase::AllSetCar(char* a2, int a3)
{
    stub<member_func_t<void, VehicleSelectBase, char*, int>>(0x4F6AF0, this, a2, a3);
}

int VehicleSelectBase::LoadStats(char* a2)
{
    return stub<member_func_t<int, VehicleSelectBase, char*>>(0x4F7340, this, a2);
}
