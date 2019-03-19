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

int Combinatorics_menu(void) {

    /* Initializing variables */
    int func, junk, n = 0;

    /* I/O flow */
    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                   >> Common fraction <<                    |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Addition                                          |\n"
"|       2) Subtractions                                      |\n"
"|       3) Multiplications                                   |\n"
"|       4) Division                                          |\n"
"|       5) Comparison                                        |\n"
"|       6) Reduction                                         |\n"
"|       7) decimal fraction                                  |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<       |\n"
"|       >> Type \"quit\" to terminate this program <<        |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '7') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n');
                no_cmd();
                continue;
            }
	    if (func<8){
	    	struct Number fr1,fr2,fr3;
		read(&fr1);
		if (func<6){
			read(&fr2);
		}
	    }
            switch (func) {
		case 1:
			add(&fr1,&fr2,&fr3);
			break;
		case 2:
			vich(&fr1,&fr2,&fr3);
			break;
		case 3:
			ymn(&fr1,&fr2,&fr3);
			break;
		case 4:
			del(&fr1,&fr2,&fr3);
			break;
		case 5:
			sravn(n,m);
			break;
		case 6:
			fr1.base+=videl(fr1.chis,fr1.znam);
			write(fr1);
			break;
		case 7:
			fr3=fr1;
			base10(fr3);
			break;
                default:
                    break;
            }

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 1;
            }

        } else if (func == 'q') {
            if (quit_m()) {
                return -1;
            } else {
                continue;
            }
        } else if (func == 'b') {
            if (back_m()) {
                return 0;
            } else {
                continue;
            }
        } else {
            no_cmd();
            while ((junk = getchar()) != '\n');
            continue;
        }
    }
}