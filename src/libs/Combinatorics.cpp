/*
ProCalc � powerful multifunctional calculator
Copyright � 2019 Tushino Software LLC

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

double Combinatorics_factorial(int limit, int min)
{
	double factorial = 1;
	
	for (int i = min;i <= limit;i++)
	{
		factorial *= i;
	}
	return factorial;
}


void Combinatorics_menu()
{
	int sign;
	do {
		do {
			printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
				"|                                                            |\n"
				"|                      >> ProCalc <<                         |\n"
				"|                                                            |\n"
				"|  >> Choose action:                                         |\n"
				"|                                                            |\n"
				"|       1) Placements with repetitions                       |\n"
				"|       2) Placements without repetitions                    |\n"
				"|       3) Combinations with repetitions                     |\n"
				"|       4) Combinations without repetitions                  |\n"
				"|       5) Permutations                                      |\n"
				"|       6) Backward                                          |\n"
				"|                                                            |\n");

			printf("| Answer: ");
			scanf("%d", &sign);
		} while ((sign > 6) || (sign < 1));

		switch (sign)
		{
		case 1: Placements_with_repetitions(); break;
		case 2: Placements_without_repetitions(); break;
		case 3: Combinations_with_repetitions(); break;
		case 4: Combinations_without_repetitions(); break;
		case 5: Permutations(); break;
		case 6: main_menu(); break;
		}

		if (sign != 6) { sign = Combinatorics_choice(); }
		
	} while (sign != 6);
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
		printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
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
		printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
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
		printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
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
		printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
		printf("| The number of combinations without repetitions of %d on %d is %.0lf \n", n, m, numerator / denominator);
	}
}

void Permutations()
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
		if (sign == 1) Permutations();
		else if (sign == 0) Combinatorics_menu();
	}
	else {
		printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
		printf("| The number of permutations of %d is %.0lf \n", n, P_n);
	}
}
