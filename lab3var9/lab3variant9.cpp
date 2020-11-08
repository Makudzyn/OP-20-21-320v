#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

/*Кунченко, 07.11.2020, Лабораторная 3, Вариант 9*/
int main()
{
	setlocale(LC_ALL, "rus");
	
	double x, y, t1, t2;
	double b = 2.33, a = 7.45, ax;
	/* ОДЗ: x && y && a && b != 0 */

	printf("Введите значение х:  ");
	scanf_s("%lf", &x);  printf("\n");

	if (x == 0)  //Проверка ОДЗ переменной х
	{
		printf("x не может быть равен нулю, введите другое значение:  ");
		scanf_s("%lf", &x); 

	}

	printf("Введите значение y:  ");
	scanf_s("%lf", &y);  printf("\n");

	if (y == 0)  //Проверка ОДЗ переменной у
	{
		printf("y не может быть равен нулю, введите другое значение:  ");
		scanf_s("%lf", &y);

	}

	ax = a * x;

	t1 = (1 / (b * b)) * (log(y / x) + (ax / y));
	printf("t1= %lf\n", t1);  printf("\n");


	while (sin(ax / 2)<0)
	{

		printf("sin(ax / 2)= %lf\n", sin(ax / 2)); printf("\n");

		printf("Введите другое значение переменной х! -> ");

		scanf_s("%lf", &x); printf("\n");

		ax = a * x; //Обновляем значение переменной умножая на полученный х

		printf("sin(ax / 2)= %lf\n", sin(ax / 2)); printf("\n");

		if (sin(ax / 2)>0) //Если нужное условие достигнуто цикл прекращает проверку
		{
			break;
		}
		
	}
	printf("\n");

	t2 = (-x / a) * tan(ax / 2) + (2 / a * a) * log(sin(ax / 2));

	printf("t2= %lf\n", t2);
	
}