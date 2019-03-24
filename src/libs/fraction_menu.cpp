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

int fraction_menu(void) {

    /* Initializing variables */
    int func, junk;

    /* I/O flow */
    while (1) {
        printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                 >> Fractions calculator <<                 |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Addition                                          |\n"
"|       2) Subtraction                                       |\n"
"|       3) Multiplication                                    |\n"
"|       4) Division                                          |\n"
"|       5) Comparison                                        |\n"
"|       6) Reduction                                         |\n"
"|       7) Decimal fraction                                  |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
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

            struct Number fr1 = {}, fr2 = {}, fr3 = {};
            read(&fr1);
            if (func < 6) {
                read(&fr2);
            }
            switch (func) {
                case 1:
                    printf("| Answer: ");
                    if (fr1.znak == fr2.znak) {
                        fr3.znak = fr1.znak;

                        add(&fr1, &fr2, &fr3);
                    }
                    else {
                        fr3.znak = true;
                        if (fr1.znak) {
                            vich(&fr2, &fr1, &fr3);
                        }
                        else {
                            vich(&fr1, &fr2, &fr3);
                        }
                    }
                    printf("\n");
                    break;
                case 2:
                    printf("| Answer: ");
                    if (fr1.znak == fr2.znak) {
                        if (!fr1.znak) { vich(&fr1, &fr2, &fr3); }
                        else { vich(&fr2, &fr1, &fr3); }
                    }
                    else {
                        if (fr2.znak) {
                            add(&fr1, &fr2, &fr3);
                        }
                        else {
                            fr3.znak = true;
                            add(&fr1, &fr2, &fr3);
                        }
                    }
                    printf("\n");
                    break;
                case 3:
                    printf("| Answer: ");
                    ymn(&fr1, &fr2, &fr3);
                    printf("\n");
                    break;
                case 4:
                    printf("| Answer: ");
                    del(&fr1, &fr2, &fr3);
                    printf("\n");
                    break;
                case 5:
                    sravn(fr1, fr2);
                    break;
                case 6:
                    printf("| Answer: ");
                    fr1.base += videl(fr1.chis, fr1.znam);
                    write(fr1);
                    printf("\n");
                    break;
                case 7:
                    printf("| Answer: ");
                    fr3 = fr1;
                    base10(fr3);
                    printf("\n");
                    break;
                default:
                    break;
            }

        prt_ln();

        while ((junk = getchar()) != '\n')
            ;

        return 1;

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
            if (func != '\n') {
                while ((junk = getchar()) != '\n')
                    ;
            }
            continue;
        }
    }
}