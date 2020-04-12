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

#include "menu.h"

#include "manager.h"

void UIMenu::Enable()
{
    stub<member_func_t<void, UIMenu>>(0x4E09D0, this);
}

void UIMenu::SetBstate(int a2)
{
    stub<member_func_t<void, UIMenu, int>>(0x4E0B20, this, a2);
}

void UIMenu::GetDimensions(float* a2, float* a3, float* a4, float* a5)
{
    *a2 = this->Position.x;
    *a3 = this->Position.y;
    *a4 = this->Scale.x;
    *a5 = this->Scale.y;
}
