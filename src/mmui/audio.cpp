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

#include "audio.h"

AudioOptions::AudioOptions(int a2)
{
    stub<member_func_t<void, AudioOptions, int>>(0x4F7AA0, this, a2);
}

int AudioOptions::FindDevice(char* a2)
{
    return stub<member_func_t<int, AudioOptions, char*>>(0x4F8D50, this, a2);
}

char* AudioOptions::GetCurrentDeviceName()
{
    return stub<member_func_t<char*, AudioOptions>>(0x4F8DD0, this);
}

void AudioOptions::ResetStereo()
{
    stub<member_func_t<void, AudioOptions, void>>(0x4F8DF0, this);
}

void AudioOptions::ResetSoundFX()
{
    stub<member_func_t<void, AudioOptions, void>>(0x4F8E10, this);
}

void AudioOptions::ResetMusic()
{
    stub<member_func_t<void, AudioOptions, void>>(0x4F8E40, this);
}

void AudioOptions::ResetAmbient()
{
    stub<member_func_t<void, AudioOptions, void>>(0x4F8E70, this);
}

void AudioOptions::ResetSoundQuality()
{
    stub<member_func_t<void, AudioOptions, void>>(0x4F8EA0, this);
}

void AudioOptions::ResetCommentary()
{
    stub<member_func_t<void, AudioOptions, void>>(0x4F8EE0, this);
}

void AudioOptions::SetDevice(int a2)
{
    stub<member_func_t<void, AudioOptions, int>>(0x4F8F00, this, a2);
}
