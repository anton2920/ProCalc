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
#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
struct Number{
	int base=0;
	int chis=0;
	int znam=0;
};
void menu_calk_drob();
void sravn(Number numb1, Number numb2); // comparison of 2 fractions
void read(Number *numb);//read fracion
int nod(struct Number,struct Number);//NOD
int nok(int,int,int);//NOK
void add(Number *numb1,Number *numb2,Number *numb3);//addition 2 fractions
void vich(Number *numb1,Number *numb2,Number *numb3);// subtraction
void del(Number *numb1,Number *numb2,Number *numb3);//division
void ymn(Number *numb1,Number *numb2,Number *numb3);// muliplication
int videl(int &a,int &b);// the allocation of the integer part
void per(Number *numb1,Number *numb2);//mixed fraction
void prev(Number *numb1, Number *numb2);//common denominator
void write(Number numb);//write fraction
void base10(Number numb);// decimal
#endif