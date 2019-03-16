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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SetsCalc. If not, see <https://www.gnu.org/licenses/>.
*/
#include "Combinatorics.h"
#include "header.h"
int Combinatorics_factorial(int limit)
{
	int factorial = 1;
	for (int i = 1;i <= limit;i++)
	{
		factorial *= i;
	}
	return factorial;
}


void Combinatorics_menu()
{
	int sign;
	do {
		system("cls");
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
		case 6: main_menu();break;
		}

		printf("\n");
		printf("| One more time - 1 \n");
		printf("| Backward - 0 \n");
		do {
			printf("| Answer: ");
			scanf("%d", &sign);
		} while ((sign > 1) || (sign < 0));
	} while (sign != 0);
}
void Placements_with_repetitions()
{
	int n, m, A_m_n = 1;
	do {
		system("cls");
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {
		system("cls");
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	for (int i = 0; i < m;i++)
	{
		A_m_n *= n;
	}
	printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf("| The number of permutations with repetitions of %d on %d is %d \n", n, m, A_m_n);
}

void Placements_without_repetitions()
{
	int n, m, numerator, denominator;
	do {
		system("cls");
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {
		system("cls");
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	numerator = Combinatorics_factorial(n);
	denominator = Combinatorics_factorial(n - m);

	printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf("| The number of permutations without repetitions of %d on %d is %d \n", n, m, numerator/denominator);
}

void Combinations_with_repetitions()
{
	int n, m, numerator, denominator_1, denominator_2;
	do {
		system("cls");
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {
		system("cls");
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	numerator = Combinatorics_factorial(n + m - 1);
	denominator_1 = Combinatorics_factorial(n - 1);
	denominator_2 = Combinatorics_factorial(m);

	printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf("| The number of combinations with repetitions of %d on %d is %d \n", n, m, numerator / (denominator_1*denominator_2));
}
void Combinations_without_repetitions()
{
	int n, m,  numerator, denominator_1, denominator_2;
	do {
		system("cls");
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 1);
	do {
		system("cls");
		printf("| Enter the number of elements in the subset. m = ");
		scanf("%d", &m);
	} while ((m < 1) || (m>n));

	numerator = Combinatorics_factorial(n);
	denominator_1 = Combinatorics_factorial(n - m);
	denominator_2 = Combinatorics_factorial(m);

	printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf("| The number of combinations without repetitions of %d on %d is %d \n", n, m, numerator / (denominator_1*denominator_2));
}

void Permutations()
{
	int n;
	do {
		system("cls");
		printf("| Enter the number of elements in the set.  n = ");
		scanf("%d", &n);
	} while (n < 0);

	printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf("| The number of permutations of %d is %d \n", n, Combinatorics_factorial(n));
}
