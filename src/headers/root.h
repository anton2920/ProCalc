#pragma once

#include "input.h"

constexpr auto eps = 1e-8;

struct Point
{
	double x, y;
};

void BisectionMethod(func& foo, double x_left, double x_right);
void extremum(func&, double, double);
double derivative(func& foo, double x);