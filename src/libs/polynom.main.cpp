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

int polynom_menu()
{
    double P[MAX_DEG] = {0},
            Q[MAX_DEG] = {0},
            R[MAX_DEG] = {0};
    int P_deg, Q_deg, R_deg = 0;
    double coef = 0.0;

    int func, junk, n;

    while (true) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                >> Polynomials calculator <<                |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Long division of polynomials                      |\n"
"|       2) Addition of polynomials                           |\n"
"|       3) Subtraction of polynomials                        |\n"
"|       4) Multiply polynomials                              |\n"
"|       5) Multiply polynomial by number                     |\n"
"|       6) Found a derivative of a polynomial                |\n"
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
                case 1: {
                    double remain[MAX_DEG] = {0},
                           new_part[MAX_DEG] = {0},
                           multiplier[MAX_DEG] = {0};
                    int remain_deg = -1;

                    P_deg = get_p(P);
                    Q_deg = get_p(Q);

                    // remain = P;
                    copy_p(remain, P);

                    for (int i = P_deg; i >= Q_deg; i--)
                    {
                        R[i - Q_deg] = multiplier[i - Q_deg] = P[i] / Q[Q_deg];
                        mult_p(multiplier, i - Q_deg, Q, Q_deg, new_part);
                        substr_this(P, P_deg, new_part, MAX_DEG-1);

                        if ( i == Q_deg )
                            copy_p(remain, P);

                        zero_p(multiplier);
                        zero_p(new_part);
                    }

                    for(int i = 0; i < MAX_DEG; i++)
                        if (remain[i] != 0)
                            remain_deg = i;

                    cout << "| Answer                                                    |\n";
                    prt_ln();
                    cout << "| Quotient: ";
                    show_p( R, P_deg - Q_deg );
                    cout << "| Remainder: ";
                    if (remain_deg == -1)
                        cout << 0 << endl;
                    else
                        show_p( remain, remain_deg );
                    prt_ln();
                }
                break;

                case 2:
                    P_deg = get_p( P );
                    Q_deg = get_p( Q );
                    R_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
                    add_p( P, P_deg, Q, Q_deg, R );
                    cout << "| Answer: ";
                    show_p( R, R_deg );
                    prt_ln();
                    break;
                case 3:
                    P_deg = get_p( P );
                    Q_deg = get_p( Q );
                    R_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
                    substr_p( P, P_deg, Q, Q_deg, R );
                    cout << "| Answer: ";
                    show_p( R, R_deg );
                    break;
                case 4:
                    P_deg = get_p( P );
                    Q_deg = get_p( Q );
                    R_deg = P_deg * Q_deg;
                    mult_p( P, P_deg, Q, Q_deg, R );
                    cout << "| Answer: ";
                    show_p( R, R_deg );
                    prt_ln();
                    break;
                case 5:
                    P_deg = get_p( P );
                    cout << "| Type multiplier: ";
                    cin >> coef;
                    R_deg = P_deg;
                    mult_number(P, P_deg, R, coef);
                    cout << "| Answer: ";
                    show_p( R, R_deg );
                    prt_ln();
                    break;
                case 6:
                    P_deg = get_p( P );
                    R_deg = P_deg - 1;
                    derivative_p(P, P_deg, R, R_deg);
                    cout << "| Answer: ";
                    show_p( R, R_deg );
                    prt_ln();
                    break;
                default:
                    break;
            }

            zero_p( P );
            zero_p( Q );


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
