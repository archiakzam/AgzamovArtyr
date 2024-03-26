#include <iostream> 
using namespace std; 
int binSearch(int* a, int N, int key) { 
    int left = 0; 
    int right = N - 1; 
    bool f = false; 
    while (!f) { 
        int mid = left + ((key - a[left]) * (right - left) / (a[right] - a[left])); 
        if (a[mid] == key) { 
            f = true; 
            return mid; 
        } 
        if (a[mid] > key) { 
            right = mid - 1; 
        } 
        if (a[mid] < key) { 
            left = mid +1; 
        } 
    } 
} 

int main() { 
    system("chcp 1251>NULL"); 
    int N; 
    cout << "¬ведите кол-во элментов в массиве: "; 
    cin >> N; 
    int* a = new int[N]; 
    for (int i = 0; i < N; i++) { 
        cout << "¬ведите " << i + 1 << " элемент: "; 
        cin >> a[i]; 
    } 
    cout << "»сходный массив: "; 
    for (int i = 0; i < N; i++) { 
        cout << a[i] << ' '; 
    } 
    cout << endl; 
    int key; 
    cout << "¬ведите key: "; 
    cin >> key; 
    int i = binSearch(a, N, key); 
    if (i != 0) { 
        cout << "Ќомер элемента, который совпал с key: " << i + 1; 
    } 
    else cout << "Ёлемента нет"; 
    return 0; 
} 