#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
struct Number {
	int base;
	int chis;
	int znam;
};
int menu_calk_drob(void);
void sravn(Number n,Number m); //������� ���������
void read(Number *numb);//������
int nod(struct Number, struct Number);//���
int nok(int, int, int);//���
void add(Number *numb1, Number *numb2);//��������
void vich(Number *numb1, Number *numb2);//���������
void del(Number *numb1, Number *numb2);//�������
void ymn(Number *numb1, Number *numb2);//���������
int videl(Number *numb);//��������� ����� ����� � ����������
void per(Number *numb);//��������� �����
void prev(Number *numb1, Number *numb2);//����� �����������
void write(Number *numb);//�����
void base10(Number *numb);//���������� �����
#endif