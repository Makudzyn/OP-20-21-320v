#include <iostream>
#include <stdlib.h>
#include <cmath>

int main(void) {
	setlocale(LC_ALL, "ru");
	int num, tmpNum;                      //Введенное число и переменная для счета
	int sum = 0, count = 0, mirroredNum = 0; //Сумма, кол-во и  число наборот
	//Вариант с массивом

	int const N = 15;                     
	int mas[N], dop;                      
	int stage = 0;                        

	printf("Введите ваше число:(1 - 2147483641) >>  ");
	scanf_s("%d", &num);
	if (num < 0) {
		num = fabs(num);
	}
	else if (num == 0) {
		printf("Число не должно равняться нулю.");
	}
	
	for (tmpNum = num; tmpNum > 0; count++){ 
		dop = tmpNum; 
	    dop %= 10; 
	    tmpNum /= 10; 
	    mas[count] = dop; 
	}
	stage = pow(10, count - 1);

	for ( int i = 0; i < count; i++){
		sum += mas[i];
		dop = mas[i]; 
		mirroredNum += stage * dop;
		stage /= 10;
	}

    /*tmpNum = num;
	for (; num != 0; count++){
		sum += num % 10;
		num /= 10;
	}
	while (tmpNum != 0){
		mirroredNum = mirroredNum * 10 + tmpNum % 10;
		tmpNum /= 10;
	}*/
	printf("\nКол-во чисел %d - Сумма %d - Наборот %d", count, sum, mirroredNum);
}

