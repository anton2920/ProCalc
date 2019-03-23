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

 void SetMtx(double **matr, int n, int m)
{
    printf("| Type the matrix                                            |\n");
    prt_ln();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("| matrix[%d][%d] = ",i,j);
            scanf("%lf", &matr[i][j]);
        }
    prt_ln();
}

 void PrintMtx(double **matr, int n, int m)
{
    printf("| Matrix                                                     |\n");
    prt_ln();
    for (int i = 0; i < n; i++) {
        printf("| ");
        for (int j = 0; j < m; j++)
        {
            printf("%.2lf ", matr[i][j]);
        }
        printf("\n");
    }
    prt_ln();
}

 void FreeMem(double **matr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matr[i];
    delete[] matr;
}

 void mat_mult(double **matr, int n, int m) //matrix mult on number
{
    int i, j;
    double p;
    printf("| Type the number: ");
    scanf("%lf", &p);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            matr[i][j] *= p;
        }
    }
    prt_ln();
}

 void mat_plus(double **matr, int n, int m)//matrix plus(minus) number
{
    int i, j, s;
    printf("| Type the number: ");
    scanf("%d", &s);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            matr[i][j] += s;
        }
    }
    prt_ln();
}

 void mats_plus(double **matr, double **matr2, int n, int m)//matix + matrix
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matr[i][j] += matr2[i][j];
        }
    }
}

 void mats_minus(double **matr, double **matr2, int n, int m)//matrix - matrix
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matr[i][j] -= matr2[i][j];
        }
    }
}

 void TransponMtx(double **matr, int n, int m)
{
    for(int i = 0; i < m; i++)
    {
        printf("| ");
        for(int j = 0; j < n; j++)
        {
            printf("%.2lf ", matr[j][i]);
        }
        printf("\n");
    }
    prt_ln();
}

 void mats_mult(double **matr1, double **matr2, double **matr3, int n, int m, int n1, int m1)//matrix * matrix
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m1; j++)
        {
            matr3[i][j] = 0;
            for(int k = 0; k < m; k++)
                matr3[i][j] += matr1[i][k] * matr2[k][j];
        }
    }

}
void Get_matr(double **matr, int n, double **temp_matr, int indRow, int indCol)
{
    int ki = 0;
    for (int i = 0; i < n; i++) {
        if (i != indRow) {
            for (int j = 0, kj = 0; j < n; j++) {
                if (j != indCol) {
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}

//==============================================================================================================
//                             Determinant
//==============================================================================================================
//matrix determiner calculation function
double Det(double **matr, int n)
{
    double temp = 0;
    int k = 1;
    if (n < 1) {
        cout << "| determinant: Incorrect matrix size!                        |\n";
        prt_ln();
        return 0;
    }
    else if (n == 1)
        temp = matr[0][0];
    else if (n == 2)
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
    else {
        for (int i = 0; i < n; i++) {
            int m = n - 1;
            double **temp_matr = new double *[m];
            for (int j = 0; j < m; j++)
                temp_matr[j] = new double[m];
            Get_matr(matr, n, temp_matr, 0, i);
            temp = temp + k * matr[0][i] * Det(temp_matr, m);
            k = -k;
            FreeMem(temp_matr, m);
        }
    }
    return temp;
}










