/*
ProCalc � powerful multifunctional calculator
Copyright � 2019 Tushino Software LLC

This file is part of ProCalc.

ProCalc is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

ProCalc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SetsCalc. If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef Combinatorics_h
#define Combinatorics_h

#ifdef _WIN32
#define CLEAR ("cls")
#endif
#ifdef __unix__
#define CLEAR ("clear")
#endif

double Combinatorics_factorial(int limit, int min);
void Combinatorics_menu();
void Placements_with_repetitions();
void Placements_without_repetitions();
void Combinations_with_repetitions();
void Combinations_without_repetitions();
void Permutations();

#endif

