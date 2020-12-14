#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int main(void) {
	setlocale(LC_ALL, "ru");
	/*srand(time(0));*/
	
	int mas[100], qst, k, pls, size, eType, masTmp, h = 0;
	printf("Введите размер массива(1-100) >>  ");
	scanf_s("%d", &size); 
	while (size >= 101 || size <= 0){
		printf("Программа не может работать с таким массивом!\n");
		printf("Введите размер массива(1-100) >>  ");
		scanf_s("%d", &size);

	}

	for (int i = 0; i < size; i++){
		mas[i] = rand() % 10 + 1;
		printf("%3d", mas[i]);
	}
	pass:
	printf("\nЕсли хотите добавить числа напишите - 1, удалить - 2:  ");
	scanf_s("%d", &qst);
	
	if (qst == 1){ 
		printf("\nКакое число добавить?(1-99) >>  ");
		scanf_s("%d", &eType);
		while (eType > 99 || eType < 1){
			printf("Вы ввели число выходящее за допустимый промежуток.\n");
			printf("\nКакое число добавить?(1-99) >>  ");
			scanf_s("%d", &eType);
		}

		printf("\nСколько чисел добавить? >>  ");
		scanf_s("%d", &k);
		while (k <= 0){
			printf("Количество чисел не может быть меньше или равняться нулю.\n");
			printf("\nСколько чисел добавить? >>  ");
			scanf_s("%d", &k);
		}

		printf("\nПосле какого номера? >>  ");
		scanf_s("%d", &pls);
		if (pls > size){
			printf("\nТак как позиция, которую вы выбрали находиться за пределами массива числа будут добавлненны в его конец.\n");
			pls = size;
		}

		for (int i = 0; i < k; i++){
			for (int i = size + k; i >= pls - 1; i--){
				if (h == 0) {
					h++;
					masTmp = mas[pls-1]; 
				}
				mas[i + 1] = mas[i];
				mas[pls - 1] = eType;
			}

		}
		mas[pls-1] = masTmp;
		for (int i = 0; i < size +k; i++){
				printf("%3d", mas[i]);
		}
	}

	else if (qst == 2){
		printf("\nСколько элементов вы хотите удалить? >>  ");
		scanf_s("%d", &k);
		printf("\nПосле какого номера? >>  ");
		scanf_s("%d", &pls);
		for (int i = 0; i < size-k; i++){
			if (k + pls > size) {
				k = size - pls;
			}
			mas[pls + i] = mas[pls + i + k];
			printf("%3d", mas[i]);
		}
		

	}
	else{
		printf("Число введено не корректно");
		goto pass;
	}
}

