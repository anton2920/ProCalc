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

using namespace Dodecahedron;

Bigint lfact(int num, int lim) {

    /* Initializing variables */
    Bigint res = 1;

    /* Main part */
    for (int i = lim; i <= num; ++i) {
        res *= i;
    }

    /* Returning value */
    return res;
}

void Combinatorics_read_n_m(int *p_n, int *p_m)
{
	do {
		printf("| Enter the number of elements in the set: ");
		scanf("%d", p_n);
	} while (*p_n < 1);

	do {
		printf("| Enter the number of elements in the subset: ");
		scanf("%d", p_m);
	} while ((*p_m < 1) || (*p_m > *p_n));
}

void Placements_with_repetitions()
{
	int n, m;
	Bigint A_m_n = 1;
	
	Combinatorics_read_n_m(&n, &m);
	
	for (int i = 0; i < m;i++)
	{
		A_m_n *= n;
	}
		
	prt_ln();
	std::cout << "| The number of placements with repetitions from " << n << " to " << m << " is " << A_m_n << "\n";
    prt_ln();
}

void Placements_without_repetitions()
{
	int n, m, i;
	Bigint A_m_n = 1;
		
	Combinatorics_read_n_m(&n, &m);

	A_m_n = lfact(n, n - m + 1);
		
	prt_ln();
    std::cout << "| The number of placements without repetitions from " << n << " to " << m << " is " << A_m_n << "\n";
    prt_ln();
}

void Combinations_with_repetitions()
{
	int n, m, i, j;
	Bigint num, denum;
	
	Combinatorics_read_n_m(&n, &m);

	if (n > (m + 1))
	{
		i = n;
		j = m;
	} else {
		i = m + 1;
		j = n - 1;
	}

    num = lfact(n + m - 1, i);
    denum = factorial(j);

	prt_ln();
	std::cout << "| The number of combinations with repetitions from " << n << " to " << m << " is " << num / denum << "\n";
    prt_ln();
}

void Combinations_without_repetitions()
{
	int n, m, i, j;
	Bigint num, denum;
	
	Combinatorics_read_n_m(&n, &m);

	if ((m + 1) > (n - m + 1))
	{
		i = m + 1;
		j = n - m;
	} else {
		i = n - m + 1;
		j = m;
	}

    num = lfact(n, i);
    denum = factorial(j);

	prt_ln();
	std::cout << "| The number of combinations without repetitions from " << n << " on " << m << " is " << num / denum << "\n";
    prt_ln();
}

void Permutations_without_repetitions()
{
	int n;
	Bigint P_n;
	
	do {
		printf("| Enter the number of elements in the set: ");
		scanf("%d", &n);
	} while (n < 0);

	P_n = factorial(n);
	
	prt_ln();
	std::cout << "| The number of permutations of " << n << " is " << P_n << "\n";
    prt_ln();
}

int Permutations_with_repetitions()
{
	int j, long_n = 0, n[1000];
	Bigint P_n, n_0 = 1;
	
	printf("| Enter the composition of the permutation with repetitions (type \"0\" to finish):  \n");
    prt_ln();
	for (j = 0; j < 1000; j++)
	{
        scanf("%d", &n[j]);
        if (n[j] == 0) {
            break;
        }

        if ((n[j] < 0) || (n[j] > 1000 - long_n)) {
            printf("| Type another number! \n");
            j--;
            continue;
        } else {
            long_n += n[j];
        }
	}
	if (n[0] == 0) { return 1; }
	else
	{
		P_n = factorial(long_n);

		for (int k = 0; k < j; k++)
		{
			n_0 *= factorial(n[k]);
		}

		P_n = P_n / n_0;

		prt_ln();
		std::cout << "| The number of permutations with repetitions is " << P_n << "\n";
		prt_ln();
		return 0;
	}
}