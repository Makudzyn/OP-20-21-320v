#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "rus");
	
	double x, y;
	

	printf("Введите координату х:  ");
	
	scanf_s("%lf", &x);

	printf("\nВведите координату y:  ");

	scanf_s("%lf", &y);
	

	if (((x >= -1 && x <= 0) && (y >= -1 && y <=0)) || (x*x + y*y > 1))
	{
		printf("\nТочка находится вне рисунка!\n");
		
	}
	else
		printf("\nТочка находится на рисунке\n");

	return 0;
	
}