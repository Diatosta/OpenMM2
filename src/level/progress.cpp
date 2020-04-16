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

#include "progress.h"

void __cdecl lvlProgress::BeginTask(char const* a1)
{
    stub<cdecl_t<void, const char*>>(0x462E30, a1);
}

void __cdecl lvlProgress::UpdateTask(float a1, bool a2)
{
    stub<cdecl_t<void, float, bool>>(0x462E80, a1, a2);
}

void __cdecl lvlProgress::EndTask()
{
    stub<cdecl_t<void>>(0x462E80);
}

void lvlProgress::SetCallback(void (*callback)(char const*, int))
{
    progressCB = callback;
}
