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
    level:progress

    0x462E30 | public: static void __cdecl lvlProgress::BeginTask(char const *) | ?BeginTask@lvlProgress@@SAXPBD@Z
    0x462E80 | public: static void __cdecl lvlProgress::UpdateTask(float,bool) | ?UpdateTask@lvlProgress@@SAXM_N@Z
    0x462F00 | public: static void __cdecl lvlProgress::PushSubTask(float,char *) | ?PushSubTask@lvlProgress@@SAXMPAD@Z
    0x462F40 | public: static void __cdecl lvlProgress::PushSubTask(float,float,char *) | ?PushSubTask@lvlProgress@@SAXMMPAD@Z
    0x462FB0 | public: static float __cdecl lvlProgress::PopSubTask(void) | ?PopSubTask@lvlProgress@@SAMXZ
    0x462FD0 | public: static float __cdecl lvlProgress::GetPercent(void) | ?GetPercent@lvlProgress@@SAMXZ
    0x463000 | public: static void __cdecl lvlProgress::EndTask(void) | ?EndTask@lvlProgress@@SAXXZ
    0x463020 | public: static void __cdecl lvlProgress::SetCallback(void (__cdecl*)(char const *,int)) | ?SetCallback@lvlProgress@@SAXP6AXPBDH@Z@Z
    private: static float * lvlProgress::sm_SubTaskEnd | ?sm_SubTaskEnd@lvlProgress@@0PAMA
    0x631678 | private: static char * * lvlProgress::sm_SubTaskName | ?sm_SubTaskName@lvlProgress@@0PAPADA
    private: static int lvlProgress::sm_SubTaskLevel | ?sm_SubTaskLevel@lvlProgress@@0HA
    private: static float * lvlProgress::sm_SubTaskStart | ?sm_SubTaskStart@lvlProgress@@0PAMA
*/

#include "hooking.h"

class lvlProgress
{
public:
    static void BeginTask(char const*);
    static void UpdateTask(float, bool);
    static void EndTask(void);
    static void SetCallback(void (*callback)(char const*, int));
};

static inline extern_var(0x631654, void (*)(const char*, int), progressCB);
static inline extern_var(0x631658, float*, float_631658);
static inline extern_var(0x631674, float*, sm_SubTaskEnd);
static inline extern_var(0x631678, char**, sm_SubTaskName);
static inline extern_var(0x631698, int, sm_SubTaskLevel);
static inline extern_var(0x63169C, float*, sm_SubTaskStart);
static inline extern_var(0x6316A0, float*, float_6316A0);
