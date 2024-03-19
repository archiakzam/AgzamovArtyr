#include <iostream>
#include <vector>
#include <ctime> // Для генерации случайных чисел

using namespace std;

// Функция для генерации случайных чисел в диапазоне [min, max]
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для сортировки Хоара
void quicksort(vector<int>& items, int left, int right) {
    int i = left, j = right, pivot = items[(left + right) / 2], tmp;
    do {
        while ((items[i] < pivot) && (i < right)) i++;
        while ((pivot < items[j]) && (j > left)) j--;
        if (i <= j) {
            tmp = items[i];
            items[i] = items[j];
            items[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) quicksort(items, left, j);
    if (i < right) quicksort(items, i, right);
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int n = 25; // Размер массива
    vector<int> arr(n);

    // Заполняем массив случайными числами в диапазоне [1, 100]
    for (int i = 0; i < n; ++i) {
        arr[i] = getRandomNumber(1, 100);
    }

    // Выводим исходный массив
    cout << "Исходный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортируем массив методом сортировки Хоара
    quicksort(arr, 0, n - 1);

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
