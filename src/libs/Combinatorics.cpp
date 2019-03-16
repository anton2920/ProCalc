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

# include "../headers/header.h"

int Combinatorics_choice()
{
	int sign;
	
	printf("\n");
	printf("| One more time - 1 \n");
	printf("| Backward - 0 \n");
	do {
		printf("| Answer: ");
		scanf("%d", &sign);
	} while ((sign > 1) || (sign < 0));
	return sign;
}

double Combinatorics_factorial(int limit, int min)
{
	double factorial = 1;
	
	for (int i = min;i <= limit;i++)
	{
		factorial *= i;
	}
	return factorial;
}

void Placements_with_repetitions()
{
	int n, m;
	double A_m_n = 1;
	do { 
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while ((n < 1) || (n>100));
	
	do {
		if (n > 40)
		do{
			printf("| Enter the number of elements in the subset. m = ");
			scanf("%d", &m);
		} while ((m > 10) || (m < 1));
		else {
			printf("| Enter the number of elements in the subset. m = ");
			scanf("%d", &m);
		}
		if (m>10) { printf("| Too big number!\n| "); }
	} while ((m < 1) || (m > n) || (m > 20));

	for (int i = 0; i < m;i++)
	{
		A_m_n *= n;
	}
	
	if (A_m_n == 0) {
		int sign;
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
		if (sign == 1) Placements_with_repetitions();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		prt_ln();
		printf("| The number of permutations with repetitions of %d on %d is %.0lf \n", n, m, A_m_n);
	}
}

void Placements_without_repetitions()
{
	int n, m, i;
	double numerator, denominator;
	do {
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	i = n - m + 1;
	numerator = Combinatorics_factorial(n, i);

	if (numerator == 0) {
		int sign;
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
		if (sign == 1) Placements_without_repetitions();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		prt_ln();
		printf("| The number of permutations without repetitions of %d on %d is %.0lf \n", n, m, numerator);
	}
}

void Combinations_with_repetitions()
{
	int n, m, i;
	double numerator, denominator;
	do {
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {		
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	i = n;
	numerator = Combinatorics_factorial(n + m - 1, i);
	denominator = Combinatorics_factorial(m, 1);
	
	if ((denominator == 0) || (numerator == 0)) {
		int sign;
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
		if (sign == 1) Combinations_with_repetitions();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		prt_ln();
		printf("| The number of combinations with repetitions of %d on %d is %.0lf \n", n, m, numerator / denominator);
	}
}

void Combinations_without_repetitions()
{
	int n, m, i;
	double numerator, denominator;
	do {
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	i = n - m + 1;
	numerator = Combinatorics_factorial(n, i);
	denominator = Combinatorics_factorial(m, 1);

	if ((denominator == 0) || (numerator == 0)) {
		int sign;
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
		if (sign == 1) Combinations_without_repetitions();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		prt_ln();
		printf("| The number of combinations without repetitions of %d on %d is %.0lf \n", n, m, numerator / denominator);
	}
}

void Permutations_without_repetitions()
{
	int n;
	double P_n;
	do {
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 0);
	P_n = Combinatorics_factorial(n, 1);
	if (n > 20) {
		int sign;
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
		if (sign == 1) Permutations_with_repetitions();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		prt_ln();
		printf("| The number of permutations of %d is %.0lf \n", n, P_n);
	}
}

void Permutations_with_repetitions()
{
	int n[100], j, long_n=0;
	double P_n;
	
	printf("| Enter the composition of the permutation with repetitions. To finish typing, enter 0 ");
	for (j = 0; j < 100; j++)
	{
		do {
			scanf("%d", &n[j]);
		} while ((j < 0) || (j > 100 - long_n));
		long_n += n[j];
		if (n[j] == 0) break;
	}

	P_n = Combinatorics_factorial(long_n, 1);
	for (int k = 0; k < j; k++)
	{
		n[k] = Combinatorics_factorial(n[k], 1);
		P_n /= n[k];
	}
	if (P_n == 0) {
		int sign;
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
		if (sign == 1) Permutations_without_repetitions();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		prt_ln();
		printf("| The number of permutations is %.0lf \n", P_n);
	}
}