#include "../headers/header.h"

double def_int(func &foo, double a, double b)
{
	double result = DBL_MAX;
	int n = ceil(b - a);
	double h = (b - a) / (2.0 * n);

	double x = a;

	bool satisfes(true);
	if (foo.name == "pow")
	{
		if (a <= 0)
			satisfes = false;
	}
	else if (foo.name == "log")
	{
		if (foo.b <= 0 && b <= 0)
			satisfes = false;
		else if (foo.b >= 0 && a <= 0)
			satisfes = false;
	}

	if (satisfes)
	{
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
	}

	return result;
}

