#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
#define N 100

void countingSort(int mass[],int size, int div) {
	int output[N];                            //Определяем 10 чередей каждая из которых представляет собой сегмент для каждой цифры от 0 до 9.
	int count[10] = { 0 };

	for (int i = 0; i < size; i++)
		count[(mass[i] / div) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(mass[i] / div) % 10] - 1] = mass[i];
		count[(mass[i] / div) % 10]--;
	}

	for (int i = 0; i < size; i++)
		mass[i] = output[i];

}

void radixSort(int mass[], int size) {
	int max = mass[0];                //Даем переменной первое значение массива
	for (int i = 1; i < size; i++) { //Находим максимальное значение массива
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	for (int div = 1; max/div > 0; div*=10){ //Для многоразового вызова сортировки подсчетом(кол-во вызовов равно максимальному числу массива)
		countingSort(mass, size, div);       //Считаем для кажого числа в массиве
	}


}
void massCreation(int mass[], int size) { //Выбор массива
	int qst;

	cout << "Какой массив используем?(Напишите соотвествующее число)\n 1 - Упорядоченный,\n\n 2 - Упорядоченный в обратном порядке массив,\n\n 3 - Неупорядоченный массив\n\n ";
	cin >> qst;
	if (qst == 1){
		cout << "Упорядоченный  массив" << endl;
		for (int i = 0; i < size; i++) {
			mass[i] = i + 1;
			cout << setw(4) << mass[i];
		}
	}
	else if (qst == 2){
		cout << "Упорядоченный в обратном порядке массив" << endl;
		for (int i = size-1; i >= 0; i--) {
			mass[i] = i;
			cout << setw(4) << mass[i];
		}
	}
	else if (qst == 3){
		cout << "Неупорядоченный массив" << endl;
	    for (int i = 0; i < size; i++) {
		mass[i] = rand() % 100 + 1;
		cout << setw(4) << mass[i];
	    }
	}
	cout << endl;
}
int main(void) {
	setlocale(LC_ALL, "ru");

	int mass[N] = { 0 };
	int size;
	long double massDuration[N], averDuration = 0;
	while (true){
		cout << "Введите размер массива >> "; cin >> size;
		cout << endl;
		massCreation(mass, size);                                     //Функция выбора массива
	    cout << endl;
	    cout << endl << "Отсортированный массив" << endl;

	for (int i = 0; i < size; i++) {

		auto start = chrono::high_resolution_clock::now();             // Начинаем отсчет
		radixSort(mass, size);                                         // Вызоваем функцию
		auto end = chrono::high_resolution_clock::now();               // Заканчиваем отсчет
		chrono::duration<double> duration = end - start;               // Находим затраченное на функцию время
		massDuration[i] = duration.count();
	}

	for (int i = 0; i < size; i++) { cout << setw(4) << mass[i]; }
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << "\nДлительность " << setw(2) << i << " > " << setprecision(12) << fixed << massDuration[i] << "s\n";
		if (i > 0) { averDuration += massDuration[i]; }
	}
	cout << endl;
	cout << "Средняя длительность" << " > "  << fixed << averDuration / (size - 1) << "s\n";
	averDuration = 0;
	massDuration[size] = { 0 };
	}
}

