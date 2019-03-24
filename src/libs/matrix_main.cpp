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

int matrix_menu() {
    int func, junk;
    while (true) {

        printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                >> Matrix calculator <<                     |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Addition (subtraction) of a matrix with a number  |\n"
"|       2) Matrix multiplication by number                   |\n"
"|       3) Addition of two matrices                          |\n"
"|       4) Subtraction of two matrices                       |\n"
"|       5) Multiplication of two matrices                    |\n"
"|       6) Matrix transpose                                  |\n"
"|       7) Matrix determinant                                |\n"
"|       8) Inverse matrix                                    |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '8') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n');
                no_cmd();
                continue;
            }


            switch (func) {
                case 1: {
                    int n, m;

                    do{
                        printf("| Type the size of matrix (#of_rows and #of_columns): ");
                        scanf("%d%d", &n, &m);
                    }while(m < 1 || n < 1);
                    prt_ln();

                    double **matr1 = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr1[i] = new double[m];
                    }

                    SetMtx(matr1, n, m);
                    mat_plus(matr1, n, m);
                    PrintMtx(matr1, n, m);

                    FreeMem(matr1, n);
                }
                    break;

                case 2: {
                    int n, m;

                    do{
                        printf("| Type the size of matrix (#of_rows and #of_columns): ");
                        scanf("%d%d", &n, &m);
                    }while(m < 1 || n < 1);
                    prt_ln();

                    double **matr1 = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr1[i] = new double[m];
                    }

                    SetMtx(matr1, n, m);
                    mat_mult(matr1, n, m);
                    PrintMtx(matr1, n, m);

                    FreeMem(matr1, n);
                }
                    break;
                case 3: {
                    int n, m;

                    do{
                        printf("| Type the size of matrix (#of_rows and #of_columns): ");
                        scanf("%d%d", &n, &m);
                    }while(m < 1 || n < 1);
                    prt_ln();

                    double **matr1 = new double *[n];
                    double **matr2 = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr1[i] = new double[m];
                        matr2[i] = new double[m];
                    }

                    SetMtx(matr1, n, m);
                    SetMtx(matr2, n, m);
                    mats_plus(matr1, matr2, n, m);
                    PrintMtx(matr1, n, m);

                    FreeMem(matr1, n);
                    FreeMem(matr2, n);
                }
                    break;
                case 4: {
                    int n, m;

                    do{
                        printf("| Type the size of matrix (#of_rows and #of_columns): ");
                        scanf("%d%d", &n, &m);
                    }while(m < 1 || n < 1);
                    prt_ln();

                    double **matr1 = new double *[n];
                    double **matr2 = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr1[i] = new double[m];
                        matr2[i] = new double[m];
                    }

                    SetMtx(matr1, n, m);
                    SetMtx(matr2, n, m);
                    mats_minus(matr1, matr2, n, m);
                    PrintMtx(matr1, n, m);

                    FreeMem(matr1, n);
                    FreeMem(matr2, n);
                }
                    break;
                case 5: {
                    int n, m, n1, m1;

                    do
                    {

                        printf("| Type the 1st matrix's size (#of_rows and #of_columns): ");
                        scanf("%d%d", &n, &m);
                    }while(n < 1 || m < 1);
                    prt_ln();

                    do {
                        printf("| Type the 2nd matrix size (#of_rows and #of_columns): ");
                        scanf("%d%d", &n1, &m1);
                        prt_ln();
                        if (m != n1) {
                            printf("| matrix: The first matrix's #of_columns must be equal to the #of_rows of the second\n");
                            prt_ln();
                        }
                    } while (m != n1 || n1 < 1 || m1 < 1);

                    double **matr1 = new double *[n];
                    double **matr2 = new double *[n1];
                    double **matr3 = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr1[i] = new double[m];
                    }
                    for (int i = 0; i < n1; i++) {
                        matr2[i] = new double[m1];
                    }
                    for (int i = 0; i < n; i++) {
                        matr3[i] = new double[m1];
                    }


                    SetMtx(matr1, n, m);
                    SetMtx(matr2, n1, m1);
                    mats_mult(matr1, matr2, matr3, n, m, n1, m1);
                    PrintMtx(matr3, n, m1);

                    FreeMem(matr1, n);
                    FreeMem(matr2, n1);
                    FreeMem(matr3, n);
                }
                    break;
                case 6: {
                    int n, m;

                    do{
                        printf("| Type the size of matrix (#of_rows and #of_columns): ");
                        scanf("%d%d", &n, &m);
                    }while(m < 1 || n < 1);
                    prt_ln();

                    double **matr1 = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr1[i] = new double[m];
                    }

                    SetMtx(matr1, n, m);
                    PrintMtx(matr1, n, m);
                    prt_ln();
                    printf("| Transposed matrix                                          |\n");
                    prt_ln();
                    TransponMtx(matr1, n, m);
                    FreeMem(matr1, n);

                }
                    break;
                case 7: {
                    int n, det;

                    do{
                        printf("| Type the size of matrix (#of_rows and columns [it will be square]): ");
                        scanf("%d", &n);
                    }while(n < 1);
                    prt_ln();

                    double **matr = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr[i] = new double[n];
                    }
                    SetMtx(matr, n, n);
                    PrintMtx(matr, n, n);
                    det = Det(matr, n);
                    printf("| Determinant = %d\n", det);
                    prt_ln();
                }
                    break;
                case 8: {
                    int n, det;

                    do{
                        printf("| Type the size of matrix (#of_rows and columns [it will be square]): ");
                        scanf("%d", &n);
                    }while(n < 1);
                    prt_ln();

                    double **matr = new double *[n];
                    double **obr_matr = new double *[n];
                    for (int i = 0; i < n; i++) {
                        matr[i] = new double[n];
                        obr_matr[i] = new double[n];
                    }
                    SetMtx(matr, n, n);
                    PrintMtx(matr, n, n);
                    det = Det(matr, n);
                    printf("| Determinant = %d\n", det);
                    prt_ln();
                    if (det) {
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < n; j++) {
                                int m = n - 1;
                                double **temp_matr = new double *[m];
                                for (int k = 0; k < m; k++)
                                    temp_matr[k] = new double[m];
                                Get_matr(matr, n, temp_matr, i, j);
                                obr_matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / det;
                                FreeMem(temp_matr, m);
                            }
                        }
                    } else {
                        cout << "| Determinant == 0 => Inverse matrix doesn't exist           |\n" << endl;
                        break;
                    }

                    //Matrix tran
                    printf("| Inverse matrix                                             |\n");
                    prt_ln();
                    TransponMtx(obr_matr, n, n);

                    FreeMem(matr, n);
                    FreeMem(obr_matr, n);
                }
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
            if (func != '\n') {
                while ((junk = getchar()) != '\n');
            }
            continue;
        }
    }
}

