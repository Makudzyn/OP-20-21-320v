#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "rus");

	float a = 2, b = 8, c = 6, ds, x1, x2;

	printf("Введите коеф. а =  ");
	scanf_s("%f", &a);

	if (a == 0)
	{
		printf("Это не квадратное уравнение!");
	}

	printf("\nВведите коеф. b =  ");
	scanf_s("%f", &b);

	printf("\nВведите коеф. c =  ");
	scanf_s("%f", &c);

	ds = b * b - 4 * a * c;

		if (ds > 0)
		{
			printf("\nДискриминант > 0 поэтому:\n");

			x1 = (-b + sqrt(ds)) / 2 * a;
			printf("\nx1 = %0.1f\n", x1);

			x2 = (-b - sqrt(ds)) / 2 * a;
			printf("\nx2 = %0.1f", x2);

		}
		else if (ds == 0)
		{
			printf("\nДискриминант = 0 поэтому:\n"); //a=3,b=6,c=3

		    x1 = (-b + sqrt(ds)) / 2 * a;
			printf("\nx1 = %0.1f", x1);
		}
		else
		{
			printf("\nДискриминант < 0, корней нет."); // a=-75,b=45,c=-76
		}

}