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

#ifndef INPUT_HEADER
#define INPUT_HEADER

struct func
{
	std::string name;
	double a, b, c, d;

	// for polynomial
	int degree;
	double *coeff;
};

double eval(func&, double);
void read(func&, const int);
void print(func&);
std::string to_string_with_precision(const double a_value, int n = 6);
void func_helper(func& );

#endif
