#include <iostream> 
using namespace std; 
int listSearch(int* a, int key, int N){ 
    int i = 0; 
    while (a[i] != key) { 
        i++; 
    } 
    if (a[i] == key) { 
        return i; 
    } 
    else return 0; 
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
    cin>> key; 
    int i =listSearch(a, key, N); 
    if (i != 0) { 
        cout << "Ќомер элемента, который совпал с key: " << i + 1; 
    } 
    else cout << "Ёлемента нет"; 
    return 0; 
} 