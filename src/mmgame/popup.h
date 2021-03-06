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
    mmgame:popup

    0x429D90 | public: __thiscall mmPopup::mmPopup(class mmGame *,float,float,float,float) | ??0mmPopup@@QAE@PAVmmGame@@MMMM@Z
    0x42A270 | public: virtual __thiscall mmPopup::~mmPopup(void) | ??1mmPopup@@UAE@XZ
    0x42A280 | public: int __thiscall mmPopup::IsEnabled(void) | ?IsEnabled@mmPopup@@QAEHXZ
    0x42A290 | public: void __thiscall mmPopup::DisablePU(int) | ?DisablePU@mmPopup@@QAEXH@Z
    0x42A320 | public: void __thiscall mmPopup::ProcessEscape(int) | ?ProcessEscape@mmPopup@@QAEXH@Z
    0x42A400 | public: void __thiscall mmPopup::ProcessChat(void) | ?ProcessChat@mmPopup@@QAEXXZ
    0x42A4B0 | public: void __thiscall mmPopup::ProcessKeymap(int) | ?ProcessKeymap@mmPopup@@QAEXH@Z
    0x42A5E0 | public: void __thiscall mmPopup::ShowResults(int) | ?ShowResults@mmPopup@@QAEXH@Z
    0x42A6D0 | public: void __thiscall mmPopup::ShowRoster(void) | ?ShowRoster@mmPopup@@QAEXXZ
    0x42A760 | public: void __thiscall mmPopup::ShowReplay(void) | ?ShowReplay@mmPopup@@QAEXXZ
    0x42A7A0 | public: void __thiscall mmPopup::ForceRoster(void) | ?ForceRoster@mmPopup@@QAEXXZ
    0x42A830 | public: virtual void __thiscall mmPopup::Update(void) | ?Update@mmPopup@@UAEXXZ
    0x42B430 | public: virtual void __thiscall mmPopup::Reset(void) | ?Reset@mmPopup@@UAEXXZ
    0x42B450 | public: char * __thiscall mmPopup::GetComment(void) | ?GetComment@mmPopup@@QAEPADXZ
    0x42B460 | public: void __thiscall mmPopup::SetComment(char *) | ?SetComment@mmPopup@@QAEXPAD@Z
    public: void __thiscall mmPopup::RecordPosition(void) | ?RecordPosition@mmPopup@@QAEXXZ
    0x42B480 | public: void __thiscall mmPopup::SaveReplay(void) | ?SaveReplay@mmPopup@@QAEXXZ
    0x42B4F0 | public: void __thiscall mmPopup::Lock(void) | ?Lock@mmPopup@@QAEXXZ
    0x42B500 | public: void __thiscall mmPopup::Unlock(void) | ?Unlock@mmPopup@@QAEXXZ
    0x42B510 | public: void __thiscall mmPopup::ChatCB(void) | ?ChatCB@mmPopup@@QAEXXZ
    0x42B570 | public: void __thiscall mmPopup::PlayPauseMusic(void) | ?PlayPauseMusic@mmPopup@@QAEXXZ
    0x42B5B0 | public: void __thiscall mmPopup::PlayReturnMusic(void) | ?PlayReturnMusic@mmPopup@@QAEXXZ
    0x42B720 | public: virtual void * __thiscall mmPopup::`scalar deleting destructor'(unsigned int) | ??_GmmPopup@@UAEPAXI@Z
    public: virtual void * __thiscall mmPopup::`vector deleting destructor'(unsigned int) | ??_EmmPopup@@UAEPAXI@Z
    0x5B0B44 | const mmPopup::`vftable' | ??_7mmPopup@@6B@
*/

// #include "hooking.h"
