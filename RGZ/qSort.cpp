#include <chrono>
#include <iostream>
#include <iomanip>


using namespace std;
// Функция быстрой сортировки(quickSort)
void qSort(int* mass, int left, int right)
{
    int referenceElem;                    // Опорный элемент
    int tmpLeft = left, tmpRight = right; // Запоминаем левую и правую границу 
    referenceElem = mass[left];           // Первое значение и будет нашим опорним елементом
    while (left < right) {
        while ((mass[right] >= referenceElem) && (left < right)) { right--; } // Задаем движение правого элемента
        if (left != right) {
            mass[left] = mass[right]; // Меняем местами right и опороный элемент
            left++;
        }
        while ((mass[left] <= referenceElem) && (left < right)) { left++; } // Задаем движение левого элемента
        if (left != right) {
            mass[right] = mass[left]; // Меняем местами значения левого и правого элементов и сдвигаем границу
            right--; 
        }
    }
    mass[left] = referenceElem;                // Ставим опроный элемент на место
    referenceElem = left;
    left = tmpLeft; right = tmpRight;
    if (left < referenceElem)                     // Повторно вызываем сортировку для левой и правой части массива
        qSort(mass, left, referenceElem - 1);
    if (right > referenceElem)
        qSort(mass, referenceElem + 1, right);
}
void massCreation(int mass[], int size) { //Выбор массива
    int qst;

    cout << "Какой массив используем?(Напишите соотвествующее число)\n 1 - Упорядоченный,\n\n 2 - Упорядоченный в обратном порядке массив,\n\n 3 - Неупорядоченный массив\n\n ";
    cin >> qst;
    if (qst == 1) {
        cout << "Упорядоченный  массив" << endl;
        for (int i = 0; i < size; i++) {
            mass[i] = i + 1;
            cout << setw(4) << mass[i];
        }
    }
    else if (qst == 2) {
        cout << "Упорядоченный в обратном порядке массив" << endl;
        for (int i = size - 1; i >= 0; i--) {
            mass[i] = i;
            cout << setw(4) << mass[i];
        }
    }
    else if (qst == 3) {
        cout << "Неупорядоченный массив" << endl;
        for (int i = 0; i < size; i++) {
            mass[i] = rand() % 100 + 1;
            cout << setw(4) << mass[i];
        }
    }
    cout << endl;
}
int main() {
    int const N = 100;
    setlocale(LC_ALL, "ru");
    int mass[N], size;
    long double massDuration[N], averDuration = 0;
    
    while (true){
        cout << "Введите размер массива >> "; cin >> size;
        cout << endl;
        massCreation(mass, size);
        cout << endl;
        cout << endl << "Отсортированный массив" << endl;

    for (int i = 0; i < size; i++) {

        auto start = chrono::high_resolution_clock::now();             // Начинаем отсчет
        qSort(mass, 0, size - 1);                                      // Вызоваем функцию
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
    cout << "Средняя длительность" << " > " << fixed << averDuration / (size - 1) << "s\n";
    averDuration = 0;
    massDuration[size] = { 0 };
    
    }
}