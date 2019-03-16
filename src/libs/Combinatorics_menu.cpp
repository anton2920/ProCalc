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
"|                    >> Combinatorics <<                     |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Placements                                        |\n"
"|       2) Combinations                                      |\n"
"|       3) Permutations                                      |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '3') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n');
                no_cmd();
                continue;
            }

            switch (func) {
                case 1:
                    n = placements_menu();
                    break;
                case 2:
                    n = combinations_menu();
                    break;
                case 3:
                    n = permutations_menu();
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

int placements_menu(void) {

    /* Initializing variables */
    int func, junk, n = 0;

    /* I/O flow */
    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                      >> Placements <<                      |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Placements with repetitions                       |\n"
"|       2) Placements without repetitions                    |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '5') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n');
                no_cmd();
                continue;
            }

            switch (func) {
                case 1:
                    Placements_with_repetitions();
                    break;
                case 2:
                    Placements_without_repetitions();
                    break;
                default:
                    break;
            }

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
            while ((junk = getchar()) != '\n');
            continue;
        }
    }
}

int combinations_menu(void) {

    /* Initializing variables */
    int func, junk, n = 0;

    /* I/O flow */
    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                     >> Combinations <<                     |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Combinations with repetitions                     |\n"
"|       2) Combinations without repetitions                  |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '2') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n');
                no_cmd();
                continue;
            }

            switch (func) {
                case 1:
                    Combinations_with_repetitions();
                    break;
                case 2:
                    Combinations_without_repetitions();
                    break;
                default:
                    break;
            }

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
            while ((junk = getchar()) != '\n');
            continue;
        }
    }

}

int permutations_menu(void) {

    /* Initializing variables */
    int func, junk, n = 0;

    /* I/O flow */
    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                     >> Permutations <<                     |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Permutations with repetitions                     |\n"
"|       2) Permutations without repetitions                  |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '2') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n');
                no_cmd();
                continue;
            }

            switch (func) {
                case 1:
                    Permutations_with_repetitions();
                    break;
                case 2:
                    Permutations_without_repetitions();
                    break;
                default:
                    break;
            }

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
            while ((junk = getchar()) != '\n');
            continue;
        }
    }

}