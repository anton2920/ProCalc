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

void base10(Number numb){
	if (numb.znak) {
		std::cout << '-';
	}
	std::cout<<numb.base+double(numb.chis)/numb.znam;
}

void sravn(Number numb1, Number numb2){
	per(&numb1,&numb2);
	prev(&numb1,&numb2);
	if (numb1.znak) {
		numb1.chis *= -1;
	}
	if (numb2.znak) {
		numb2.chis *= -1;
	}
	if (numb1.chis > numb2.chis){
		std::cout<<"| First fraction is greater than second one                  |\n";
	}
	else if (numb1.chis < numb2.chis){
		std::cout<<"| First fraction is less than second one                     |\n";
	}
	else{
		std::cout<<"| Fractions are equal to each other                           |\n";
	}
}

void read(Number *numb){
	numb->znak = false;
	do{
		printf("| Type the fraction in the format A B C                      |\n");
		prt_ln();
		printf("| A — basis                                                  |\n"
			"| B — numerator                                              |\n"
			"| C — denominator                                            |\n");
		prt_ln();
		printf("| Answer: ");
		std::cin>>numb->base>>numb->chis>>numb->znam;
	}while(numb->znam==0);
	if (numb->base<0 || numb->chis<0 || numb->znam < 0) {
		numb->znak = true;
	}
	numb->base = abs(numb->base);
	numb->chis = abs(numb->chis);
	numb->znam = abs(numb->znam);
    prt_ln();
}

void write(Number k){
	if (k.znak) {
		std::cout << '-';
	}
	if (k.chis==0 && k.base==0) std::cout<<0;
	if (k.base!=0) std::cout<<k.base<<" ";
	if (k.chis!=0) std::cout<<k.chis<<"/"<<k.znam;
}

int nod(int a,int b){
	while (a*b>0){
		a>b? a%=b:b%=a;
	}
	return (a+b);
}

int nok(int a,int b){
	return (a*b/nod(a,b));
}

void add(Number *numb1,Number *numb2,Number *numb3){
	numb3->base=numb1->base+numb2->base;
	prev(numb1,numb2);
	numb3->znam=numb1->znam;
	numb3->chis=numb1->chis+numb2->chis;
	numb3->base=numb1->base+numb2->base;
	numb3->base+=videl(numb3->chis,numb3->znam);
	write(*numb3);
}

void vich(Number *numb1,Number *numb2,Number *numb3){
	int flag=1;
	per(numb1,numb2);
	prev(numb1,numb2);
	numb3=numb1;
	if (numb2->chis>numb1->chis){
		numb3=numb2;
		numb2=numb1;
		numb1=numb3;
		flag=-1;
	}
	numb3->znam=numb1->znam;
	numb3->chis=numb1->chis-numb2->chis;
	//k.base+=videl(k.chis,k.znam);
	numb3->base=videl(numb3->chis,numb3->znam);
	numb3->base*=flag;
	write(*numb3);
}

void del(Number *numb1,Number *numb2,Number *numb3){
	int x;
	per(numb1,numb2);
	x=numb2->chis;
	numb2->chis=numb2->znam;
	numb2->znam=x;
	if (numb2->znam==0){
		std::cout<<"| fractions: zero division error!                            |\n"; //you can div by 0
	}
	else{
		ymn(numb1,numb2,numb3);//div by multi
	}
}

void ymn(Number *numb1,Number *numb2,Number *numb3){
	numb3->znak = !(numb1->znak==numb2->znak);
	per(numb1,numb2);
	numb3->chis=numb1->chis*numb2->chis;
	numb3->znam=numb1->znam*numb2->znam;
	numb3->base+=videl(numb3->chis,numb3->znam);
	write(*numb3);
}

int videl(int &a,int &b){
	int m=0;
	if (a>=b){
		m=a/b;
		a-=b*m;		
	}
	int prom=nod(a,b);
	a/=prom;
	b/=prom;
	return m;
}

void per(Number *numb1,Number *numb2){
	numb1->chis+=numb1->znam*numb1->base;
	numb1->base=0;
	numb2->chis+=numb2->znam*numb2->base;
	numb2->base=0;
}

void prev(Number *numb1,Number *numb2){
	int prom1=nok(numb1->znam,numb2->znam);
	numb1->chis=prom1/numb1->znam*numb1->chis;
	numb2->chis=prom1/numb2->znam*numb2->chis;
	numb1->znam=prom1;
	numb2->znam=prom1;
}
