#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(0));

	short a, b, rightRes, userRes, attCount = 0, points = 0;
	

	while (attCount < 10) {

		a = rand() % 7 + 4;
		b = rand() % 8 + 3;

		rightRes = a * b;
		attCount++;

		printf("Пример: %hi * %hi\n", a,b);
		printf("Введите ответ:  ");
		scanf_s("%hi", &userRes);

		printf("\n");

		if (rightRes == userRes) {
			points += 10;
		}
	}
	printf("Ваша оценка:  %hi", points);
}
