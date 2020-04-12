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

#include "card2d.h"

void Card2D::SetDimensions(float x, float y, float w, float h)
{
    double v5;
    float v7;

    if (x >= 0.0)
    {
        if (x > 1.0)
        {
            x = 1.0;
        }
    }
    else
    {
        x = 0.0;
    }

    if (y >= 0.0)
    {
        if (y > 1.0)
        {
            y = 1.0;
        }
    }
    else
    {
        y = 0.0;
    }

    v5 = 1.0 - x;

    if (w >= 0.0)
    {
        if (w > v5)
        {
            w = v5;
        }
    }
    else
    {
        w = 0.0;
    }

    v7 = 1.0 - y;

    if (h >= 0.0)
    {
        if (h > v7)
        {
            h = v7;
        }
    }
    else
    {
        h = 0.0;
    }

    this->Pos.x = x;
    this->Pos.y = y;
    this->Size.x = w;
    this->Size.y = h;
}
