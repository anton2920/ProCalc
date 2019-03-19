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

void Combinatorics_read_n_m(int *p_n, int *p_m)
{
	do {
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", p_n);
	} while ((*p_n < 1) || (*p_n > 100));

	do {
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", p_m);
	} while ((*p_m < 1) || (*p_m > *p_n));
}

unsigned long long int Combinatorics_factorial(int limit, int min)
{
	unsigned long long int factorial = 1;
	
	for (int i = min;i <= limit;i++)
	{
		factorial *= i;
	}
	return factorial;
}

void Placements_with_repetitions()
{
	int n, m, sign = 0;
	unsigned long long int  A_m_n = 1;
	do{
		Combinatorics_read_n_m(&n, &m);
	
		for (int i = 0; i < m;i++)
		{
			A_m_n *= n;
		}
		if (A_m_n <=0 )
		{
			printf("| Too big number!\n| ");
			sign = Combinatorics_choice();
		}
	} while (sign != 0); 
	prt_ln();
	printf("| The number of placements with repetitions of %d on %d is %lli \n", n, m, A_m_n);
    	prt_ln();
}

void Placements_without_repetitions()
{
	int n, m, i, sign=0;
	unsigned long long int  A_m_n = 1;
	do{
		
		Combinatorics_read_n_m(&n, &m);

		i = n - m + 1;
		A_m_n = Combinatorics_factorial(n, i);
		if (A_m_n <= 0)
		{
			printf("| Too big number!\n| ");
			sign = Combinatorics_choice();
		}
	} while (sign != 0);
	
	prt_ln();
	printf("| The number of placements without repetitions of %d on %d is %lli \n", n, m, A_m_n);
    prt_ln();
}

void Combinations_with_repetitions()
{
	int n, m, i, j, sign=0;
	unsigned long long int numerator, denominator;
	do{
		Combinatorics_read_n_m(&n, &m);

		if (n> (m+1))
		{
			i = n;
			j = m;
		}
		else {
			i = m + 1;
			j = n - 1;
		}
		numerator = Combinatorics_factorial(n + m - 1, i);
		denominator = Combinatorics_factorial(j, 1);
	
		if ((denominator <= 0) || (numerator <= 0)) {
			printf("| Too big number!\n| ");
			sign = Combinatorics_choice();
		}
	} while (sign != 0);
	prt_ln();
	printf("| The number of combinations with repetitions of %d on %d is %lli \n", n, m, numerator / denominator);
    	prt_ln();
}

void Combinations_without_repetitions()
{
	int n, m, i, j, sign=0;
	unsigned long long int numerator, denominator;
	do{
		Combinatorics_read_n_m(&n, &m);

		if ((m + 1) > (n - m + 1))
		{
			i = m + 1;
			j = n - m;
		}
		else {
			i = n - m + 1;
			j = m;
		}

		numerator = Combinatorics_factorial(n, i);
		denominator = Combinatorics_factorial(j, 1);

		if ((denominator <= 0) || (numerator <= 0)) {
			printf("| Too big number!\n| ");
			sign = Combinatorics_choice();
		}
	} while (sign != 0);
	prt_ln();
	printf("| The number of combinations without repetitions of %d on %d is %lli \n", n, m, numerator / denominator);
    	prt_ln();
}

void Permutations_without_repetitions()
{
	int n, sign=0;
	unsigned long long int P_n;
	
	do{
		do {
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 0);

	P_n = Combinatorics_factorial(n, 1);
	
	if (P_n <= 0) {
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
	}
} while (sign != 0);
	prt_ln();
	printf("| The number of permutations of %d is %lli \n", n, P_n);
    	prt_ln();
}

void Permutations_with_repetitions()
{
	int j, long_n=0, sign=0, n[100];
	unsigned long long int P_n;
	do{
	printf("| Enter the composition of the permutation with repetitions. To finish typing, enter 0 \n");
	for (j = 0; j < 100; j++)
	{
			scanf("%d", &n[j]);
			if ((n[j] < 0) || (n[j] > 100 - long_n)) { printf("| Too big number! Enter another number. \n"); j--; }
			long_n += n[j];
			if (n[j] == 0) break;
	}

	P_n = Combinatorics_factorial(long_n, 1);
	
	for (int k = 0; k < j; k++)
	{
		n[k] = Combinatorics_factorial(n[k], 1);
		P_n /= n[k];
	}

	if (P_n <= 0) {
		printf("| Too big number!\n| ");
		sign = Combinatorics_choice();
	}
	} while (sign != 0);
		prt_ln();
		printf("| The number of permutations is %lli \n", P_n);
    prt_ln();
}