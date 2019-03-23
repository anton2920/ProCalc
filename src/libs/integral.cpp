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

#include "../headers/header.h"

double def_int(func &foo, double a, double b, bool *check)
{
	double result = DBL_MAX;
	int n = ceil(b - a);
	double h = (b - a) / (2.0 * n);

	double x = a;

	bool satisfes(true);
	if (foo.name == "pow")
	{
		if (a <= 0)
		{
			if (abs(foo.b - static_cast<int> (foo.b)) <= 1e-9) {}
			else
				satisfes = false;
		}
	}
	else if (foo.name == "log")
	{
		if (foo.b <= 0 && b <= 0 || foo.b >= 0 && a <= 0)
			satisfes = false;
	}

	if (satisfes)
	{
		result = 0;
		result += eval(foo, x);
		x += h;

		for (int i = 1; i < 2 * n; ++i)
		{
			if (i % 2 == 0)
			{
				result += 2 * eval(foo, x);
			}
			else
			{
				result += 4 * eval(foo, x);
			}
			x += h;
		}

		result += eval(foo, x);
		result = result * (b - a) / (6.0*n);
	}
	else
	{
		std::cout << "| integral: Invalid segment!                                 |\n";
		*check = false;
	}

	return result;
}

