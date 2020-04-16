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

#include "dlg_msg.h"

Dialog_Message::Dialog_Message(int a2, float a3, float a4, float a5, float a6, char* a7)
{
    stub<member_func_t<void, Dialog_Message, int, float, float, float, float, char*>>(
        0x4FD3D0, this, a2, a3, a4, a5, a6, a7);
}

void Dialog_Message::Init(int a2, char* a3, char* a4)
{
    stub<member_func_t<void, Dialog_Message, int, char*, char*>>(0x4FD4F0, this, a2, a3, a4);
}
