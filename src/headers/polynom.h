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
along with ProCalc. If not, see <https://www.gnu.org/licenses/>.
*/

#define MAX_DEG 100

using namespace std;

void mult_p(const double * P, int P_deg, const double * Q, int Q_deg, double * R );
void mult_number(double * P, int P_deg, double * R, double n);
void derivative_p(double * P, int P_deg, double * R, int R_deg);
void add_p(const double * P, int P_deg, const double * Q, int Q_deg, double * R );
void substr_p(const double * P, int P_deg, const double * Q, int Q_deg, double * R );
void zero_p(double * P);
int get_p( double * P );
void show_p( const double * P, int deg );
int polynom_menu();

