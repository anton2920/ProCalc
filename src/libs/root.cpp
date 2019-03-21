#include "../headers/header.h"

void BisectionMethod(func& foo, double x_left, double x_right)
{
	if (eval(foo, x_left) * eval(foo, x_right) >= 0)
	{
		std::cout << "Wrong interval!\n";
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

	std::cout << "The value of root is : " << mid_point << '\n';
}

void extremum(func& foo, double a, double b)
{
	std::cout << "Extreme points:\n";

	double step = 1e-9;
	for (double cur_x = a + step; cur_x < b; cur_x += step)
	{
		if (abs(derivative(foo, cur_x)) <= 1e-7 &&
			derivative(foo, cur_x - step) * derivative(foo, cur_x + step) < 0)
		{
			std::cout << "x = " << cur_x << "	y = " << derivative(foo, cur_x) << '\n';
			cur_x += 1e-6;
		}
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