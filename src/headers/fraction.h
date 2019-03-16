#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
struct Number {
	int base;
	int chis;
	int znam;
};
int menu_calk_drob(void);
void sravn(Number n,Number m); //функция сравнения
void read(Number *numb);//чтение
int nod(struct Number, struct Number);//НОД
int nok(int, int, int);//НОК
void add(Number *numb1, Number *numb2);//сложение
void vich(Number *numb1, Number *numb2);//вычитание
void del(Number *numb1, Number *numb2);//деление
void ymn(Number *numb1, Number *numb2);//умножение
int videl(Number *numb);//выделение целой части и сокращение
void per(Number *numb);//смешанная дробь
void prev(Number *numb1, Number *numb2);//общий знаменатель
void write(Number *numb);//вывод
void base10(Number *numb);//десятичная дробь
#endif