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

#include "manager.h"

MenuManager::MenuManager()
{
    stub<member_func_t<void, MenuManager>>(0x4E2DF0, this);
}

MenuManager::~MenuManager()
{
    stub<member_func_t<void, MenuManager>>(0x4E3490, this);
}

void MenuManager::AddPointer()
{
    stub<member_func_t<void, MenuManager>>(0x4E4030, this);
}

void MenuManager::CheckBG(UIMenu* menu)
{
    this->SetBackgroundImage((char*)menu->Background);
}

void MenuManager::SetDefaultBackgroundImage(char* a2)
{
    if (a2)
    {
        strcpy((char*)this->DefaultBackground, a2);
        MenuManager::SetBackgroundImage(a2);
    }
    else
    {
        this->DefaultBackground = 0;
        MenuManager::SetBackgroundImage(0);
    }
}

void MenuManager::SetBackgroundImage(char* a2)
{
    stub<member_func_t<void, MenuManager, const char*>>(0x4E4FA0, this, a2);
}

void MenuManager::AdjustPopupCard(UIMenu* menu)
{
    float x, y, w, h;

    menu->GetDimensions(&x, &y, &w, &h);
    this->CheckBG(menu);
    this->pCard->SetDimensions(x, y, w, h);
}

void MenuManager::OpenDialog(int a2)
{
    stub<member_func_t<void, MenuManager, int>>(0x4E5110, this, a2);
}

void MenuManager::Enable(int a2)
{
    signed int menu;
    signed int fgColor;

    menu = MenuManager::FindMenu(a2);

    if (menu >= 0)
    {
        fgColor = this->FGColor;
        this->CurrentMenu = a2;

        if (!fgColor || this->PUEnabled)
        {
            this->ppMenus[menu]->Enable();
            if (this->FGColor)
            {
                this->AdjustPopupCard(this->ppMenus[menu]);
            }
            this->CheckBG(this->ppMenus[menu]);
        }
    }
}

void MenuManager::EnableNavBar()
{
    uiNavBar* navBar = this->pNavBar;

    if (navBar)
    {
        navBar->menu.asNode.Flags |= 1u;
        navBar->TurnOnPrev();
    }
}

int MenuManager::FindMenu(int a2)
{
    UIMenu** ppUiMenu;
    signed int menuCount;
    signed int result = 0;

    menuCount = this->nMenuCount;

    if (menuCount <= 0)
    {
        return -1;
    }

    ppUiMenu = this->ppMenus;
    while (!*ppUiMenu || (*ppUiMenu)->MenuID != a2)
    {
        ++result;
        ++ppUiMenu;

        if (result >= menuCount)
        {
            return -1;
        }
    }

    return result;
}

void MenuManager::SetFocus(UIMenu* menu)
{
    this->FocusedMenu = menu;
}
