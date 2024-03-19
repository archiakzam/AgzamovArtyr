#include <iostream>
#include <vector>
#include <ctime> // Для генерации случайных чисел

using namespace std;

// Функция для генерации случайных чисел в диапазоне [min, max]
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для сортировки Шелла
void shellSort(vector<int>& arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int n = 25; // Размер массива
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = getRandomNumber(1, 100);
    }

    cout << "Исходный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    shellSort(arr, n);
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
