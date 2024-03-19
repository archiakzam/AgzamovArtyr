#include <iostream>
#include <vector>
#include <ctime> // Для генерации случайных чисел

using namespace std;

// Функция для генерации случайных чисел в диапазоне [min, max]
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция сортировки подсчетом
void countSort(vector<int>& arr, int n) {
    // Находим максимальное значение в массиве
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Создаем массив `output` размера `n` для хранения отсортированных элементов
    vector<int> output(n);

    // Создаем массив `count` размера `maxVal + 1`, инициализируем его нулями
    vector<int> count(maxVal + 1, 0);

    // Используя значение каждого элемента входного массива в качестве индекса,
    // сохраняем счетчик каждого целого числа в `count[]`
    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    // Копируем в выходной массив, сохраняя порядок входов с одинаковыми ключами
    int outputIndex = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i] > 0) {
            output[outputIndex] = i;
            --count[i];
            ++outputIndex;
        }
    }

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << output[i] << " ";
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

    // Сортируем массив методом подсчета
    countSort(arr, n);

    return 0;
}