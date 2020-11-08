//11.10.2020 Kunchenko

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()

{
	double x, y;
	printf("Your numb=");
	scanf_s("%lf", &x);
	y = x + x * 0.65;
	printf("Computer numb=%0.1lf\n", y);
	if (y > x) printf("Computer wins!");
}