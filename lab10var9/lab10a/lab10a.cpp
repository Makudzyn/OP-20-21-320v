#include <iostream>

char sravnenie(int num1, int num2) {
	if (num1 == num2) { return'='; }
	if (num1 > num2) { return'>'; }
	if (num1 < num2) { return'<'; }
}

int main(){
	setlocale(LC_ALL, "ru");
	int a, b;
	printf("Введите значения которые хотите сравнить : \n");
	while (true){
		printf("\n");
		printf("Первое число >>  ");  scanf_s("%d", &a);
		printf("Второе число >>  ");  scanf_s("%d", &b);

		printf("%d %c %d", a, sravnenie(a, b), b);
	}	
}

