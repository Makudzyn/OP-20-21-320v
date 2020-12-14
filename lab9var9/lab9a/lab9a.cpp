#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int const N = 7;
int const M = 9;
int mas[N][M],mas2[N][M];

int main(void) {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int const lim = 100;
	printf("Исходный массив\n");
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			mas[i][k] = rand() % lim + 1;
			mas2[i][k] = mas[i][k];
			printf("%4d", mas[i][k]);
		}
		printf("\n");
	}

	int itmp = 0, ktmp = 0, keep = 0;
	/*1*/
	for (int i = 0; i < N; i++) { // Столбцы
		int max = 0;
		for (int k = 0; k < M; k++) {
			keep = mas[i][0];
			if (mas[i][k] >= max) {                      
				max = mas[i][k];
				itmp = i; ktmp = k;
			}
			if (k == M - 1) {
				mas[i][0] = max;
				mas[itmp][ktmp] = keep;
			}
		}
	}
	printf("\nИзмененный массив(1)\n");
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			printf("%4d", mas[i][k]);
		}
		printf("\n");
	}
	/*2*/
	for (int k = 0; k < M; k++) {
		int min = lim;
		for (int i = 0; i < N; i++) { // Столбцы
			keep = mas2[N - 1][k];
			if (mas2[i][k] <= min){
				min = mas2[i][k];
				itmp = i; ktmp = k;
			}
			if (i == N - 1) {
				mas2[N-1][k] = min;
				mas2[itmp][ktmp] = keep;
			}
		}
	}
	printf("\nИзмененный массив(2)\n");
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			printf("%4d", mas2[i][k]);
		}
		printf("\n");
	}
}

