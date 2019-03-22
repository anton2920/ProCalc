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

#ifndef SRC_MATRIX_H
#define SRC_MATRIX_H

using namespace std;

void FreeMem(double **matr, int n);
void PrintMtx(double **matr, int n, int m);
void SetMtx(double **matr, int n, int m);
void TransponMtx(double **matr, int n, int m);
void mat_mult(double **matr, int n, int m);
void mat_plus(double **matr, int n, int m);
void mats_plus(double **matr, double **matr2, int n, int m);
void mats_minus(double **matr, double **matr2, int n, int m);
void mats_mult(double **matr1, double **matr2, double **matr3, int n, int m, int n1, int m1);
void Get_matr(double **matr, int n, double **temp_matr, int indRow, int indCol);
double Det(double **matr, int n);
int matrix_menu();

#endif
