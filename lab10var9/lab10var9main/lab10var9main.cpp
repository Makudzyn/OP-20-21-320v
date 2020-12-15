#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int const N = 100;

int convertToDmMas(int odnomernyMas[N], int masSize, int stlb, int str) {
	int max = 0, itmp = 0, jtmp = 0, sum = 0, tmp = 0;
	int dmMas[N][N] = { 0 },tmpMas;
	for (int i = 0; i < stlb; i++){
		for (int j = 0; j < str; j++) {
			dmMas[i][j] = odnomernyMas[i * str + j];
			printf("%3d", dmMas[i][j]);	
		}
		printf("\n");
	}
	for (int i = 0; i < stlb; i++) {
		for (int j = 0; j < str; j++) {   //Сумма єлементов строки
			sum += dmMas[i][j];
		if (dmMas[i][j] >= max) {        //Нахождение найбольшего
			max = dmMas[i][j];
			itmp = i; jtmp = j;
		}
		if (j == str - 1) {
			dmMas[itmp][jtmp] = sum;
			sum = 0;
		}
	    }
	}
	printf("Измененный двумерный массив\n");
	for (int i = 0; i < stlb; i++) {
		for (int j = 0; j < str; j++, tmp++) {
			printf("%3d", dmMas[i][j]);
			odnomernyMas[tmp] = dmMas[i][j];
		}
		printf("\n");
	}
	
    return 0;
}

int main(void){
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int size = 0, a1, a2;
	int omMas[N] = { 0 };

	printf("Задайте размер двумерного массива(По его размерам будет создан одномерный)\n");
	printf("\nВыбирайте такие числа которые при умножении будут меньше 100");
	printf("\nРазмер столбца >>  "); scanf_s("%d", &a1);
	printf("\nРазмер строки  >>  "); scanf_s("%d", &a2);
	while ((a1 * a2) > 100 || (a1*a2) < 0 || a1*a2 == 0){
		printf("\nНедопустимое произведение!\n\n");
		printf("Задайте размер двумерного массива(По его размерам будет создан одномерный)");
		printf("\nРазмер столбца >>  "); scanf_s("%d", &a1);
		printf("\nРазмер строки  >>  "); scanf_s("%d", &a2);
	}
   
	size = a1 * a2;
	printf("\nРазмер одномерного массива :  %d\n", size);
	
	printf("Одномерный массив :\n");
	for (int k = 0; k < size; k++){
		omMas[k] = rand() % 10 + 1;
		printf("%3d", omMas[k]);
	}
	printf("\nДвумерный массив\n");

	convertToDmMas(omMas, size, a1, a2); //Вызов функции

	printf("Измененный одномерный массив :\n"); //Печать измененного массива
	for (int k = 0; k < size; k++) {
		printf("%3d", omMas[k]);
	}

}
