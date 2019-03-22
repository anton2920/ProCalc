#ifndef INPUT_HEADER
#define INPUT_HEADER

struct func
{
	/*
	functions name:
	sin - sinus			a*sin(b*x+c)+d
	cos - cosines		a*cos(b*x+c)+d
	exp - exponential	a*b^(c*x)+d
	pow - power			a*x^b+c
	log - logarithmic	a*ln(b*x)+c
	pol - polynomial	a0+a1*x+a2*x^2+...+aN*x^N
	*/
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
