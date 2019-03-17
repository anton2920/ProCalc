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

#ifndef Combinatorics_h
#define Combinatorics_h

/* Combinatorics.cpp */
unsigned long long int Combinatorics_factorial(int limit, int min);
void Combinatorics_read_n_m(int *p_n, int * p_m);
void Placements_with_repetitions();
void Placements_without_repetitions();
void Combinations_with_repetitions();
void Combinations_without_repetitions();
void Permutations_with_repetitions();
void Permutations_without_repetitions();

/* Combinatorics_menu.cpp */
int Combinatorics_menu(void);
int placements_menu(void);
int combinations_menu(void);
int permutations_menu(void);

#endif

