// 10.10.2020 Kunchenko

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	double a, b, c, s, p;

	printf("Storona a=");
	scanf_s("%lf", &a);

	printf("Storona b=");
	scanf_s("%lf", &b);

	printf("Storona c=");
	scanf_s("%lf", &c);

	p = (a + b + c) / 2;
	printf("p = %lf \n", p);

	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("s = %lf \n", s);
}
