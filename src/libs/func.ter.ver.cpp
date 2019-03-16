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
along with SetsCalc. If not, see <https://www.gnu.org/licenses/>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "../headers/header.h"
struct diskraspr
{
	int x;
	double p;
};
double probability()
{
	int alltry, deftry;
	double ver;
	printf("| Enter number of all try ");
	do
		scanf("%d", &alltry);
	while (alltry < 1);
	printf("| Enter number of the outcames interesting you ");
	do
		scanf("%d", &deftry);
	while (deftry < 1);
	ver = (deftry * 1.0 / alltry) * 100;
	printf("| Probability of an outcome is equal %3.2lf %%\n", ver);
	return ver;
}
int key(diskraspr*row, int nrow)
{

	printf("| Enter number of elements of a row \n");
	do
		scanf("%d", &nrow);
	while (nrow < 2 || nrow>100);
	printf("| Set a row of X\n");
	for (int i = 0; i < nrow; i++)
	{
		printf("x%d=", i+1);
		scanf("%d", &row[i].x);
		printf("p%d=", i+1);
		scanf("%lf", &row[i].p);
	}
	return nrow;
}
double MathWait(diskraspr*row, int nrow)
{
	double sum = 0, sump = 0;
	int u = key(row, nrow);
	for (int j = 0; j < u; j++)
	{
		sum += row[j].x*row[j].p;
		sump += row[j].p;
	}
	if (sump != 1)
	{
		printf("| Sum of p must be equal 1");
		return 1;
	}
	else
	{
		printf("| Mathmetical expectation is equal %3.3lf\n", sum);
		return 0;
	}
}
double Dispercia(diskraspr*row, int nrow)
{
	double sum1 = 0, sump = 0, sum2 = 0, sumd = 0;
	int u = key(row, nrow);
	for (int j = 0; j < u; j++)
	{
		sum1 += row[j].x*row[j].p;
		sump += row[j].p;
	}
	if (sump != 1)
	{
		printf("| Sum of p must be equal 1");
		return 1;
	}
	for (int i = 0; i < u; i++)
	{
		sum2 += row[i].x*row[i].x*row[i].p;
	}
	sumd = sum2 - sum1 * sum1;
	printf("| Dispersion is equal %2.2lf\n ", sumd);
	return 0;

}