//11.10.2020 Kunchenko

#include<iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	long long s = 60, m = 60, h = 24, d = 365, vd = 366, y = 1, sol;

	//������� ���
	sol = s * m * h * d * y;
	//printf("Seconds in one year=%0.lf\n", sol);

	//���������� ���
	sol = s * m * h * vd * y;
	//printf("Seconds in leap year=%0.lf\n", sol);

	//100 ���
	y = 100;
	sol = s * m * h * d * y;
	//printf("Seconds in 100 years=%0.lf\n", sol);

	//1000 ���
	y = 1000;
	sol = s * m * h * d * y;
	//printf("Seconds in 1000 years=%0.lf", sol);
}