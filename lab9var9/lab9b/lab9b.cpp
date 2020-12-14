#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int main(void) {
	/*srand(time(0));*/
	setlocale(LC_ALL, "ru");

	int const X = 30;
	int	mas1[X][X], mas2[X][X], finalmas[X][X] = { 0 };
	int a1, b1, a2, b2;

	printf("Задайте размерность первой матрицы(1-30) >> \n");
	printf("\nКол-во столбцов : "); scanf_s("%d", &a1);
	printf("\nКол-во строк    : "); scanf_s("%d", &b1);

	printf("\nЗадайте размерность второй матрицы >> \n");
	printf("\nКол-во столбцов : "); scanf_s("%d", &a2);
	printf("\nКол-во строк    : "); scanf_s("%d", &b2);

	while (a1 != b2 || a1 == 0 || a2 == 0 || b1 == 0 || b2 == 0) {
		printf("\nПроизведение такой матрицы посчитать невозможно.\nПопробуйте еще раз: \n");
		printf("\nЗадайте размерность первой матрицы >> \n");
		printf("\nКол-во столбцов : "); scanf_s("%d", &a1);
		printf("\nКол-во строк    : "); scanf_s("%d", &b1);

		printf("\nЗадайте размерность второй матрицы >> \n");
		printf("\nКол-во столбцов : "); scanf_s("%d", &a2);
		printf("\nКол-во строк    : "); scanf_s("%d", &b2);
	}
	printf("\nПервая матрица\n");
	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < b1; j++) {
			mas1[i][j] = rand() % 10 - 5;
			printf("%3d", mas1[i][j]);
		}
		printf("\n");
	}
	printf("\nВторая матрица\n");
	for (int i = 0; i < a2; i++) {
		for (int j = 0; j < b2; j++) {
			mas2[i][j] = rand() % 5 + 1;
			printf("%3d", mas2[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < a1; i++){
		for (int j = 0; j < b2; j++){
			for (int k = 0; k < a2; k++){
				finalmas[i][j] += mas1[i][k] * mas2[k][j];
			}
		}
	}
	printf("\nПроизведение матриц\n");
	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < b2; j++) {
			printf("%4d", finalmas[i][j]);
		}
		printf("\n");
	}
}
