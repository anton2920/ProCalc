/*
ProCalc — powerful multifunctional calculator
Copyright © 2019 Tushino Software LLC

This file is part of ProCalc.

ProCalc is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

ProCalc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProCalc. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include "header.h"

#if (HAVE_SDL2_SDL_H == 1 || HAVE_SDL_H == 1 || HAVE_SDL_SDL_H == 1)

struct PC {
    int ratio_x;
    int ratio_y;
    int size;
    int window_width;
    int window_height;
};

bool SDL_start(SDL_Window**, SDL_Renderer**, PC *);
void clear_window(SDL_Renderer*);
void plotGraph(SDL_Renderer*, func&, int, int, PC *);
void draw_y_axis(SDL_Renderer* renderer, int, PC *);
void draw_x_axis(SDL_Renderer* renderer, int, PC *);
void draw_grid(SDL_Renderer*, PC *);

#endif

#endif

