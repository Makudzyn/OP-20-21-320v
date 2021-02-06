#include <iostream>
#include <ctime>

#define N 20
using namespace std;

int Rec(int negArr[], int amount, int k, int m) {
	if (k == amount){
		printf("Произведение отрицательных чисел >> %d",m);
		return m;
	}
	m *= negArr[k];
	k++;
	//cout << m;
	return Rec(negArr, amount, k, m);
}


int main() {
	setlocale(LC_ALL, "ru");
	//srand(time(0));
	int counter = 0, a = 0, b = 1;
	int arr[N] = { 0 }, negArr[N] = { 0 };

	printf("Одномерный массив : ");
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 10 - 5;
		printf("%4d", arr[i]);
		if (arr[i] < 0) {
			counter++;
			negArr[counter-1] = arr[i];
		}
	}
	printf("\n");
	Rec(negArr, counter, a, b);
}
