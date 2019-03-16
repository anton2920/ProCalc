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

#include "../headers/header.h"
#include "../headers/polynom.h"


void mult_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R )
{
    for (int i = 0; i <= P_deg; i++)
        for (int j = 0; j <= Q_deg; j++)
            R[i + j] += P[i] * Q[j];
}

void mult_number( double * P, const int P_deg, const double n )
{
    for (int i = 0; i <= P_deg; i++)
        P[i] *= n;
}

void derivative_p( double * P, const int P_deg )
{
    for (int i = 0; i <= P_deg; i++)
        P[i] *= i;

    // shift array
    for (int i = 0; i <= P_deg; i++)
        P[i] = P[i + 1];

    P[P_deg] = 0;
}

void add_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R )
{
    int max_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
    for (int i = 0; i <= max_deg; i++)
        R[i] = P[i] + Q[i];
}

void substr_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R )
{
    int max_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
    for (int i = 0; i <= max_deg; i++)
        R[i] = P[i] - Q[i];
}

void copy_p( double * to, const double * from )
{
    for(int i = 0; i < MAX_DEG; i++)
        to[i] = from[i];
}

void zero_p(double * P)
{
    for(int i = 0; i < MAX_DEG; i++)
        P[i] = 0;
}

int polynom_menu()
{

    int func, junk, n;

    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
               "|                                                            |\n"
               "|                      >> ProCalc <<                         |\n"
               "|                                                            |\n"
               "|  >> Choose a function:                                     |\n"
               "|                                                            |\n"
               "|       1) Keyboard-typed goods                              |\n"
               "|       2) Pseudo-randomly generated goods                   |\n"
               "|       3) Containment of a text file                        |\n"
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
                    // n = n_menu();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                default:
                    break;
            }

            if (!n) {
                func = 'b';
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
            while ((junk = getchar()) != '\n')
                ;
            continue;
        }
    }
}


int main()
{
    double P[MAX_DEG] = {0},
            Q[MAX_DEG] = {0},
            temp[MAX_DEG] = {0},
            temp2[MAX_DEG] = {0},
            R[MAX_DEG] = {0};
    int P_deg, Q_deg, R_deg, temp_deg, temp2_deg;


    do {
        cout << "Insert P polynom degree\n\nFor example:\nIf P(x) = 1*x^5 + 6*x^3 - 2*x^2 + 5*x - 13\nthen degree = 5\n";
        cin >> P_deg;
    } while( P_deg <= 0 || P_deg >= MAX_DEG );

    cout << "Insert P polynom coefficients\n\nFor example:\nIf P(x) = 1*x^5 + 6*x^3 - 2*x^2 + 5*x - 13\nthen coefficients is = -13 5 -2 6 0 1 \n";
    for (int i = 0; i <= P_deg; i++)
        cin >> P[i];

    do {
        cout << "Insert Q polynom degree\n";
        cin >> Q_deg;
    } while( Q_deg <= 0 || Q_deg >= MAX_DEG );


    cout << "Insert P polynom coefficients\n";
    for (int i = 0; i <= Q_deg; i++)
        cin >> Q[i];

    R_deg = (P_deg > Q_deg) ? P_deg : Q_deg;



    // вывести результат в виде многочлена
    cout << "\n=== RESULT: ===\n";
    for(int i = R_deg; i >= 0; i-- ) {

        if ( R[i] < 0 )
            cout << "- ";
        else if ( R[i] > 0 && i != R_deg ) // для первого слагаемого "+" выводить как-то некрасиво
            cout << "+ ";
        else if ( i != R_deg ) // тут коэф. равен 0, нифига не выводим
            continue;

        if (i != 0) // для свободного члена x^0 писать не надо
            cout << R[i] << "x^" << i << " ";
        else
            cout << R[i];
    }

    cout << endl;

}