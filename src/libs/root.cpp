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

void BisectionMethod(func& foo, double x_left, double x_right)
{
	if (eval(foo, x_left) * eval(foo, x_right) >= 0)
	{
		std::cout << "| root: Wrong interval! (function must change its sign)      |\n";
		return;
	}

	double mid_point = x_left;

	while ((x_right - x_left) >= eps)
	{
		mid_point = (x_left + x_right) / 2.0;

		if (eval(foo, mid_point) == 0.0)
			break;

		else if (eval(foo, mid_point) * eval(foo, x_left) < 0)
			x_right = mid_point;
		else
			x_left = mid_point;
	}

	std::cout << "| The value of root is: " << mid_point << '\n';
}

void extremum(func& foo, double a, double b)
{
	if (foo.name == "pow")
	{
		if (a <= 0)
			std::cout << "| extreme: Wrong interval! (left bound must be positive)     |\n";
		    prt_ln();
	}
	else
	{
		std::cout << "| Extreme points (this may take a while)                     |\n";
		prt_ln();
		double step = 1e-9;
		for (double cur_x = a + step; cur_x < b; cur_x += step)
		{
			if (abs(derivative(foo, cur_x)) <= 1e-6 &&
				derivative(foo, cur_x - step) * derivative(foo, cur_x + step) < 0)
			{
				std::cout << "| x = " << cur_x << "; y(x) = " << eval(foo, cur_x) << '\n';
				cur_x += 1e-6;
			}
		}
        prt_ln();
	}
}

double derivative(func& foo, double x)
{
	double result;
	if (foo.name == "sin")
	{
		result = (foo.a*foo.b) + cos(foo.b * x + foo.c);
	}
	else if (foo.name == "cos")
	{
		result = -(foo.a*foo.b) + sin(foo.b *x + foo.c);
	}
	else if (foo.name == "exp")
	{
		result = foo.a*foo.c + log(foo.b) + pow(foo.b, foo.c*x);
	}
	else if (foo.name == "pow")
	{
		result = foo.a*foo.b + pow(x, foo.b - 1);
	}
	else if (foo.name == "log")
	{
		result = foo.a / x;
	}
	else if (foo.name == "pol")
	{
		result = 0;
		if (foo.degree > 0)
		{
			result += foo.coeff[1];
			for (unsigned i = 2; i <= foo.degree; ++i)
			{
				if (foo.coeff[i] == 0)
					continue;
				result = result + (foo.coeff[i] * i) * pow(x, i - 1);
			}
		}
		else
			result = 0;
	}

	return result;
}