#include <iostream>
#include <vector>
#include <ctime> // Для генерации случайных чисел

using namespace std;

// Функция для генерации случайных чисел в диапазоне [min, max]
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для блочной сортировки
void bucketSort(vector<int>& arr, int n) {
    // Находим максимальное значение в массиве
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Создаем "карманы" (buckets) для каждого диапазона значений
    vector<vector<int>> buckets(maxVal + 1);

    // Распределяем элементы по "карманам"
    for (int i = 0; i < n; ++i) {
        int bucketIndex = (arr[i] * n) / (maxVal + 1);
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Сортируем каждый "карман" отдельно (например, с помощью вставки)
    for (int i = 0; i <= maxVal; ++i) {
        for (int j = 1; j < buckets[i].size(); ++j) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                --k;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Собираем отсортированный массив из "карманов"
    int outputIndex = 0;
    for (int i = 0; i <= maxVal; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[outputIndex] = buckets[i][j];
            ++outputIndex;
        }
    }

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
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

    // Сортируем массив методом блочной сортировки
    bucketSort(arr, n);

    return 0;
}