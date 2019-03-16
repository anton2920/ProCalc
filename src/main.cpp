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

#include "headers/header.h"
#include "headers/fraction.h"
#include "headers/Combinatorics.h"
#include "headers/polynom.h"
#include "headers/TeoriaVer.h"

int main(int argc, const char *argv[]) {

    /* Initializing variables */
    int func;

    /* Main part */
    do {
        func = main_menu();
        if (func == -1) {
            break;
        }
    } while (menu_continue());

    /* Returning value */
    return 0;
}

/* Functions definitions */
void prt_ln(void) {

    /* Final output */
    printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
}

void no_cmd(void) {

    /* Final output */
    printf("| menu: no such command!                                     |\n");
}

int quit_m(void) {

    /* Initializing variables */
    int junk;

    /* Main part */
    if ((junk = getchar()) == 'u') {
        if ((junk = getchar()) == 'i') {
            if ((junk = getchar()) == 't') {
                if ((junk = getchar()) == '\n') {
                    return -1;
                } else {
                    no_cmd();
                    while ((junk = getchar()) != '\n')
                        ;
                    return 0;
                }
            } else {
                no_cmd();
                if (junk == '\n') {
                    return 0;
                } else {
                    while ((junk = getchar()) != '\n');
                    return 0;
                }
            }
        } else {
            no_cmd();
            if (junk == '\n') {
                return 0;
            } else {
                while ((junk = getchar()) != '\n');
                return 0;
            }
        }
    } else {
        no_cmd();
        if (junk == '\n') {
            return 0;
        } else {
            while ((junk = getchar()) != '\n');
            return 0;
        }
    }
}

int back_m(void) {
    /* Initializing variables */
    int junk;

    /* Main part */
    if ((junk = getchar()) == 'a') {
        if ((junk = getchar()) == 'c') {
            if ((junk = getchar()) == 'k') {
                if ((junk = getchar()) == '\n') {
                    return -1;
                } else {
                    no_cmd();
                    while ((junk = getchar()) != '\n')
                        ;
                    return 0;
                }
            } else {
                no_cmd();
                if (junk == '\n') {
                    return 0;
                } else {
                    while ((junk = getchar()) != '\n');
                    return 0;
                }
            }
        } else {
            no_cmd();
            if (junk == '\n') {
                return 0;
            } else {
                while ((junk = getchar()) != '\n');
                return 0;
            }
        }
    } else {
        no_cmd();
        if (junk == '\n') {
            return 0;
        } else {
            while ((junk = getchar()) != '\n');
            return 0;
        }
    }
}

int main_menu(void) {

    /* Initializing variables */
    int func, junk, n = 0;

    /* I/O flow */
    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                     >> ProCalc v1.0 <<                     |\n"
"|                                                            |\n"
"|  >> Choose a type of a calculator:                         |\n"
"|                                                            |\n"
"|       1) Matrix calculator                                 |\n"
"|       2) Fractions calculator                              |\n"
"|       3) Combinatorial stuff calculator                    |\n"
"|       4) Polynomials calculator                            |\n"
"|       5) Probability and statistics                        |\n"
"|       6) Functions stuff                                   |\n"
"|                                                            |\n"
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
                    break;
                case 2:
                    break;
                case 3:
                    // n = Combinatorics_menu();
                    break;
                case 4:
                    n = polynom_menu();
                    break;
                case 5:
                    n = verdant_menu();
                    break;
                case 6:
                    break;
                default:
                    break;
            }

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 0;
            }

        } else if (func == 'q') {
            if (quit_m()) {
                return -1;
            } else {
                continue;
            }
        } else {
            no_cmd();
            while ((junk = getchar()) != '\n')
                ;
            continue;
        }
    }
}

int menu_continue(void) {

    /* Initializing variables */
    int func, junk;

    /* I/O flow */
    while (1) {
        printf("| Continue? [y/N]: ");
        switch ((func = getchar())) {
            case 'y': case 'Y':
                if ((junk = getchar()) != '\n') {
                    while ((junk = getchar()) != '\n')
                        ;
                    prt_ln();
                    continue;
                }
                prt_ln();
                return 1;
            case 'n': case 'N': case '\n':
                if (func == 'n' || func == 'N') {
                    if ((junk = getchar()) != '\n') {
                        while ((junk = getchar()) != '\n')
                            ;
                        prt_ln();
                        continue;
                    }
                }
                prt_ln();
                return 0;
            default:
                while ((junk = getchar()) != '\n')
                    ;
                prt_ln();
                continue;
        }
    }
}