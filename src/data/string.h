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

#pragma once

/*
    data:string

    char * __cdecl StringDuplicate(char const *) | ?StringDuplicate@@YAPADPBD@Z
    0x4C81D0 | char * __cdecl formatf(char *,int,char const *,...) | ?formatf@@YAPADPADHPBDZZ
*/

#include "hooking.h"

class string
{
public:
    char* pBuffer;
    int nBufferSize;

    string();
};
