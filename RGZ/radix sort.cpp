//#include <algorithm>
//#include <iterator>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
// Поразрядная сортировка (radix sort)

typedef struct slist_ {
    int val;
    struct slist_* next;
} slist;

slist* radixsort(slist* L, int t) //Двусвязный список 
{
    int i, j, d, m = 1;
    slist* temp, * head[10], * tail[10];

    // Обработка t цифр
    for (j = 1; j <= t; j++){
        // Инициализируем очереди, от 0 до 9
        for (i = 0; i <= 9; i++){
            head[i] = 0;
            tail[i] = 0;
        }

        // Обрабатываем L лист
        while (L != 0){
            // Получаем десятичное число с разрядным значением m
            d = static_cast<int>(L->val / m) % 10;

            // Создаем временную точку для текущего элемента списка
            temp = L;

            // Делам чтобы L указывал на следующий элемент списка
            L = L->next;

            // Отключаем текущий элемент списка, делая его автономным
            temp->next = 0;

            if (head[d] != 0){   // Очередь для цифры пока она не пуста

                // Добавляем элемент списка в конец очереди для d
                tail[d]->next = temp;

                // Делаем чтобы конец [d] указывал на новый элемент конца очереди d
                tail[d] = temp;
            }
            else{                // Очередь на цифру d пуста
                head[d] = temp;  // Указываем на новое начало 
                tail[d] = temp;  // Указываем на новый конец
            }
        }

        // Находим индекс d первой непустой очереди
        d = 0;
        while (head[d] == 0)
            d++;

        // Указываем на первый элемент первой непустой очереди
        L = head[d];

        // Указываем на последний элемент первой непустой очереди
        temp = tail[d];

        // Добавляем элементы оставшихся непустых очередей в конец списка L
        d++;
        while (d < 10)
        {
            if (head[d] != 0)
            {
                // Добавляем элементы непустой очереди d в список L
                temp->next = head[d];

                // Указываем на новый конец списка L
                temp = tail[d];
            }

            d++;
        } 

        // Подготовка к обработке следующей, более значащей цифры
        m = m * 10;
    }

    return L;
}

int main(){
    // Инициализируйте начальное число случайных чисел со временем
    srand(time(0));
    setlocale(LC_ALL, "ru");

    const int N = 45;
    int mass[N];
    long double massDuration[N], averDuration = 0;
    int i, max = -1, t = 0;

    // Генерируем случайные числа
    slist* start = 0, * end = 0, * temp; 
    /*cout << "Упорядоченный  массив" << endl;
    for (int i = 0; i < N; i++) {
        mass[i] = i + 1;
        cout << setw(4) << mass[i];
    }*/
    printf("Упорядоченный в обратном порядке массив\n");
    for (int i = N - 1; i >= 0; i--) {
        mass[i] = i;
        cout << setw(4) << mass[i];

    }

    // Находим наибольшее значение и создаем связанный список случайных значений
    for (i = 0; i < N; i++){
        // Find the largest value
        if (mass[i] > max)
            max = mass[i];

        // Create a new node
        temp = new slist;

        // Fill the node with a random value
        temp->val = mass[i];

        // Seal the node
        temp->next = 0;

        if (start != 0)
        {   // Append the new node to the linked list
            end->next = temp;
            end = temp;
        }
        else
        {   // Add the first node to the linked list
            start = temp;
            end = temp;
        }
    }

    // Find the number of decimal digits in the largest random value
    while (max > 0)
    {
        t = t + 1;
        max = max / 10;
    }

    
    // Используем функцию сортировки

    cout << endl;
    cout << endl << "Отсортированный массив" << endl;
    
    for (int i = 0; i < N; i++) {

        auto begin = chrono::high_resolution_clock::now();             // Начинаем отсчет
        start = radixsort(start, t);                                   // Вызоваем функцию
        auto end = chrono::high_resolution_clock::now();               // Заканчиваем отсчет
        chrono::duration<double> duration = end - begin;               // Находим затраченное на функцию время
        massDuration[i] = duration.count();
    }
    temp = start;
    for (i = 0; i < N; i++){
        cout << temp->val << "\n";
        temp = temp->next;
    }

    for (int i = 0; i < N; i++) { cout << setw(4) << mass[i]; }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << "\nДлительность " << i << " > " << setprecision(12) << fixed << massDuration[i] << "s\n";
        if (i > 0) { averDuration += massDuration[i]; }
    }
    cout << "Средняя длительность" << " > " << fixed << averDuration / (N - 1) << "s\n";

    return 0;
} 