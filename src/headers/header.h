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

#ifndef PROCALC_MAIN_HEADER_FILE
#define PROCALC_MAIN_HEADER_FILE

/* config.h */
#include "config.h"

/* Including standard libraries */
#if (HAVE_CMATH == 1)
	#include <cmath>
#endif
#if (HAVE_CSTDIO == 1)
	#include <cstdio>
#endif
#if (HAVE_IOSTREAM == 1)
	#include <iostream>
#endif
#if (HAVE_SDL2_SDL_H == 1)
	#include <SDL2/SDL.h>
#elif (HAVE_SDL_H == 1)
	#include <SDL.h>
#elif (HAVE_SDL_SDL_H == 1)
	#include <SDL/SDL.h>
#endif

/* Including local headers */
#include "fraction.h"
#include "Combinatorics.h"
#include "polynom.h"
#include "TeoriaVer.h"
#include "bigint.h"

/* main.cpp */
void prt_ln(void);
void no_cmd(void);
int back_m(void);
int quit_m(void);
int main_menu(void);
int menu_continue(void);

#endif
