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

#include "playerdir.h"

void mmPlayerDirectory::SetLastPlayer(char* a2)
{
    stub<member_func_t<void, mmPlayerDirectory, char*>>(0x526640, this, a2);
}

int mmPlayerDirectory::GetNumPlayers()
{
    return stub<member_func_t<int, mmPlayerDirectory>>(0x5266C0, this);
}

char* mmPlayerDirectory::GetLastPlayer()
{
    return stub<member_func_t<char*, mmPlayerDirectory>>(0x5266D0, this);
}

int mmPlayerDirectory::AddPlayer(char* a2)
{
    return stub<member_func_t<int, mmPlayerDirectory, char*>>(0x526700, this, a2);
}

char* mmPlayerDirectory::GetFileName(char* a2)
{
    return stub<member_func_t<char*, mmPlayerDirectory, char*>>(0x5269A0, this, a2);
}

int mmPlayerDirectory::Load(char* a2)
{
    return stub<member_func_t<int, mmPlayerDirectory, char*>>(0x526CA0, this, a2);
}

int mmPlayerDirectory::Save(char* a2, int a3)
{
    return stub<member_func_t<int, mmPlayerDirectory, char*, int>>(0x526CA0, this, a2, a3);
}
