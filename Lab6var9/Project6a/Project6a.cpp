#include <iostream>
#include <ctime>

int main(){
    	
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int pcNum = 0, userNum = 0, attCount = 0;

	pcNum = rand() % 100;
	printf("%d\n", pcNum); //Проверка числа компьютера

	while (pcNum != userNum) {

		printf("Угадайте целое число от 0 до 100:   ");
		scanf_s("%d", &userNum);
		attCount++;

		if (userNum > pcNum) {
			printf("Ваше число больше того, которое загадал компьютер!");

		}
		if (userNum < pcNum) {
			printf("Ваше число меньше того, которое загадал компьютер!");

		}
		if (userNum == pcNum) {
			printf("\nПравильно!Вы угадали число %d с %d-ой попытки\n", pcNum, attCount);
		}
	}






}
