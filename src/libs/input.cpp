#include "input.h"

double eval(func& foo, double coord_x)
{
	double result;

	if (foo.name == "sin")
	{
		result = foo.a*sin(foo.b*coord_x + foo.c) + foo.d;
	}
	else if (foo.name == "cos")
	{
		result = foo.a*cos(foo.b*coord_x + foo.c) + foo.d;
	}
	else if (foo.name == "exp")
	{
		result = foo.a*pow(foo.b, foo.c*coord_x) + foo.d;
	}
	else if (foo.name == "pow")
	{
		if (coord_x <= 0)
			result = DBL_MAX;
		else
			result = foo.a*pow(coord_x, foo.b) + foo.c;
	}
	else if (foo.name == "log")
	{
		if (foo.b*coord_x <= 0)
			result = DBL_MAX;
		else
			result = foo.a*log(foo.b*coord_x) + foo.c;
	}
	else if (foo.name == "pol")
	{
		double temp_x = 1.0;
		result = 0;
		for (unsigned i = 0; i <= foo.degree; ++i)
		{
			result += foo.coeff[i] * temp_x;
			temp_x *= coord_x;
		}
	}

	return result;
}

void read(func &foo, const int mode)
{
	switch (mode)
	{
	case 1:
	{
		foo.name = "sin";
		func_helper(foo);
		std::cout << "Enter a: ";
		std::cin >> foo.a;
		std::cout << "Enter b: ";
		std::cin >> foo.b;
		std::cout << "Enter c: ";
		std::cin >> foo.c;
		std::cout << "Enter d: ";
		std::cin >> foo.d;
		break;
	}
	case 2:
	{
		foo.name = "cos";
		func_helper(foo);
		std::cout << "Enter a: ";
		std::cin >> foo.a;
		std::cout << "Enter b: ";
		std::cin >> foo.b;
		std::cout << "Enter c: ";
		std::cin >> foo.c;
		std::cout << "Enter d: ";
		std::cin >> foo.d;
		break;
	}
	case 3:
	{
		foo.name = "exp";
		func_helper(foo);
		std::cout << "Enter a: ";
		std::cin >> foo.a;
		std::cout << "Enter b: ";
		std::cin >> foo.b;
		std::cout << "Enter c: ";
		std::cin >> foo.c;
		std::cout << "Enter d: ";
		std::cin >> foo.d;
		break;
	}
	case 4:
	{
		foo.name = "pow";
		func_helper(foo);
		std::cout << "Enter a: ";
		std::cin >> foo.a;
		std::cout << "Enter b: ";
		std::cin >> foo.b;
		std::cout << "Enter c: ";
		std::cin >> foo.c;
		break;
	}
	case 5:
	{
		foo.name = "log";
		func_helper(foo);
		std::cout << "Enter a: ";
		std::cin >> foo.a;
		std::cout << "Enter b: ";
		std::cin >> foo.b;
		std::cout << "Enter c: ";
		std::cin >> foo.c;
		break;
	}
	case 6:
	{
		foo.name = "pol";
		func_helper(foo);
		do
		{
			std::cout << "Enter degree: ";
			std::cin >> foo.degree;
		} while (foo.degree < 0);

		foo.coeff = new double[foo.degree + 1];

		for (unsigned i = 0; i <= foo.degree; ++i)
		{
			std::cout << "Enter a" << i << ": ";
			std::cin >> foo.coeff[i];
		}
		break;
	}
	}
}

void print(func& foo)
{
	std::cout << "You entered: ";
	std::string function = "";
	if (foo.name == "sin")
	{
		function += to_string_with_precision(foo.a) + "*sin(" + to_string_with_precision(foo.b) + "x+" + to_string_with_precision(foo.c) + ")+" + to_string_with_precision(foo.d);
		std::cout << function;
	}
	else if (foo.name == "cos")
	{
		function += to_string_with_precision(foo.a) + "*cos(" + to_string_with_precision(foo.b) + "x+" + to_string_with_precision(foo.c) + ")+" + to_string_with_precision(foo.d);
		std::cout << function;
	}
	else if (foo.name == "exp")
	{
		function += to_string_with_precision(foo.a) + "*" + to_string_with_precision(foo.b) + "^(" + to_string_with_precision(foo.c) + "x)+" + to_string_with_precision(foo.d);
		std::cout << function;
	}
	else if (foo.name == "pow")
	{
		function += to_string_with_precision(foo.a) + "*x^" + to_string_with_precision(foo.b) + "+" + to_string_with_precision(foo.c);
		std::cout << function;
	}
	else if (foo.name == "log")
	{
		function += to_string_with_precision(foo.a) + "*log(" + to_string_with_precision(foo.b) + "x)+" + to_string_with_precision(foo.c);
		std::cout << function;
	}
	else if (foo.name == "pol")
	{

		function += to_string_with_precision(foo.coeff[0]);

		for (unsigned i = 1; i <= foo.degree; ++i)
		{
			if (foo.coeff[i] == 0) {}
			else if (i == 1)
			{
				function += "+" + to_string_with_precision(foo.coeff[i]) + "*x";
			}
			else
			{
				function += "+" + to_string_with_precision(foo.coeff[i]) + "*x^" + to_string_with_precision(i);

			}

		}
		std::cout << function;
	}
	std::cout << "\n";
}

std::string to_string_with_precision(const double a_value, int n)
{
	if (abs(abs(a_value) - int(abs(a_value))) <= 0.000001)
		n = 0;
	std::ostringstream out;
	out.precision(n);
	out << std::fixed << a_value;
	return out.str();
}

void func_helper(func& foo)
{
	std::cout << "example: ";

	if (foo.name == "sin")
	{
		std::cout << "a*sin(b*x+c)+d" << '\n';
	}
	else if (foo.name == "cos")
	{
		std::cout << "a*cos(b*x+c)+d" << '\n';
	}
	else if (foo.name == "exp")
	{
		std::cout << "a*b^(c*x)+d" << '\n';
	}
	else if (foo.name == "pow")
	{
		std::cout << "a*x^b+c" << '\n';
	}
	else if (foo.name == "log")
	{
		std::cout << "a*log(b*x)+c" << '\n';
	}
	else if (foo.name == "pol")
	{
		std::cout << "a0+a1*x+a2*x^2+...+aN*x^N" << '\n';
	}
}