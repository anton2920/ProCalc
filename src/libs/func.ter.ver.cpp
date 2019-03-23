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

void probability(void)
{
	int alltry, deftry;
	double ver;
	do {
        do {
            printf("| Enter the number of outcomes: ");
            scanf("%d", &alltry);
        } while (alltry < 1);

		do {
            printf("| Enter number of the outcomes, which interests you: ");
            scanf("%d", &deftry);
        } while (deftry < 0);
		if (alltry < deftry)
			printf("| Number of all outcomes has to be less than outcomes, which interests you \n");
	} while (alltry < deftry);

	ver = (deftry * 1.0 / alltry) * 100;

    prt_ln();
	printf("| Probability of an outcome equals to %3.2lf%%%s                |\n", ver, (floor(ver) == 100.0) ? "" : " ");
    prt_ln();
}

int key(diskraspr *row, int nrow)
{
    double sump = 0;
	do {
        printf("| Enter number of elements of a row: ");
        scanf("%d", &nrow);
    } while (nrow < 2 || nrow > 100);
    prt_ln();
    do {
		sump = 0;
        printf("| Set a row of X and probability P                           |\n");
        prt_ln();
        for (int i = 0; i < nrow; i++) 
		{
            printf("| x[%d] = ", i + 1);
            scanf("%d", &row[i].x);
			do {
				printf("| p[%d] = ", i + 1);
				scanf("%lf", &row[i].p);
				if (row[i].p > 1) {
                    prt_ln();
                    printf("| ter.ver: p[%d] cannot be more than one!\n", i + 1);
                    prt_ln();
                }
			} while (row[i].p > 1);
            sump += row[i].p;
            prt_ln();
        }
		if (abs(1 - sump) > 1e-10) {
            prt_ln();
            printf("| Sum of P must be equals to one                             |\n");
            prt_ln();
        }
    } while (abs(1 - sump) > 1e-10);

	return nrow;
}

void MathWait(diskraspr *row, int nrow)
{
	double sum = 0;
	int u = key(row, nrow);
	for (int j = 0; j < u; j++)
	{
		sum += row[j].x*row[j].p;
		
	}

	printf("| Mathematical expectation equals to %2.2lf\n", sum);
    prt_ln();
}

void Dispercia(diskraspr *row, int nrow)
{
	double sum1 = 0,sum2 = 0, sumd = 0;
	int u = key(row, nrow);
	for (int j = 0; j < u; j++)
	{
		sum1 += row[j].x*row[j].p;

		
	}
	for (int i = 0; i < u; i++)
	{
		sum2 += row[i].x*row[i].x*row[i].p;
	}
	sumd = sum2 - sum1 * sum1;

	printf("| Dispersion equals to %2.2lf\n", sumd);
    prt_ln();
}