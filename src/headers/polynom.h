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

#define MAX_DEG 100

void mult_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R );
void mult_number( double * P, const int P_deg, const double n );
void derivative_p( double * P, const int P_deg );
void add_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R );
void substr_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R );
void copy_p( double * to, const double * from );
void zero_p(double * P);
int polynom_menu();

