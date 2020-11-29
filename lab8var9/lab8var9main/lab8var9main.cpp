#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	setlocale(LC_ALL, "ru");
	srand(time(0));

	int const N = 200;
	int mass[N] = { 0 }; 
	int sumMax = 0, temp = 0, masIndex = 0, n = 0;

	 for (int i = 0; i < N; i++) {

		mass[i] = rand() % 100;            //Массив случайных чисел
		printf("%3d ", i);                 //Индекс чисел массива
		printf("Значение %d\n", mass[i]);  //Вывод чисел массива
		if (i % 10 == 0)
		{
			printf("----------------\n");
		}
	 }

	 for (int i = 0; i < 10; i++) {        //Нахождение суммы первых 10 элементов
		 temp += mass[i];
		 sumMax = temp;                       //Полученную сумму кладем в переменную 
	 }

	 for (int i = 1; i < 191; i++) {       
		 temp += mass[i + 9] - mass[i - 1]; //Находим сумму следущих 10 чисел отнимая первый член и прибавляя новый
		 if (temp > sumMax)                   //Сравнение новой и предыдущей суммы
		 {
			 sumMax = temp;
			 masIndex = i;
		 }
	 }
	 
	 for (int i = 0; i < 10; i++)
		 printf("%d ", mass[masIndex + i]);
	
	printf("Summ %d %d %d", sumMax, temp, masIndex);
}