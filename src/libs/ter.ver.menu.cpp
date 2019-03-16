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
#define _CRT_SECURE_NO_WARNINGS
#include "../headers/TeoriaVer.h"
#include "../headers/header.h"
int verdant_menu(void) {
	struct diskraspr row[100];
	/* Initializing variables */
	int func, junk, n, nrow = 0;

	/* I/O flow */
	while (1) {
		printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
			"|                                                            |\n"
			"|                      >> ProCalc <<                         |\n"
			"|                                                            |\n"
			"|  >> Choose a function:                                     |\n"
			"|                                                            |\n"
			"|       1) Probability m/n                                   |\n"
			"|       2) Dispercia                                         |\n"
			"|       3) Mathematical expectation                           |\n"
			"|                                                            |\n"
			"|       >> Type \"back\" to go to the previous menu <<         |\n"
			"|       >> Type \"quit\" to terminate this program <<          |\n"
			"|                                                            |\n");
		printf("| Answer: ");
		func = getchar();
		prt_ln();
		if (isdigit(func) && func >= '1' && func <= '6') {
			func -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n')
					;
				no_cmd();
				continue;
			}

			switch (func) {
			case 1:
				probability();
				break;
			case 2:
				Dispercia(row, nrow);
				break;
			case 3:
				MathWait(row, nrow);
				break;
			default:
				break;
			}

			if (!n) {
				func = 'b';
			}

		}
		else if (func == 'q') {
			if (quit_m()) {
				return -1;
			}
			else {
				continue;
			}
		}
		else if (func == 'b') {
			if (back_m()) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			no_cmd();
			while ((junk = getchar()) != '\n')
				;
			continue;
		}
	}
}