#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
const int n = 5;
int k, K;
int a[n];

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "¬ведите индекс k: ";
    cin >> K;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 20;
        cout << a[i] << " ";
    }
    cout << endl;
    int i = 0;
    k = K;
    for (int i = 0; i < n; i++) {
        if (k == n-1) {
            cout << a[k] << " ";
            k = 0;
            }
        else {

            cout << a[k] << " ";
            k++;
        }
    }
    cout << endl;
    k = K;
    for (int i = 0; i < n; i++) {
        if (k == n-1) {
            if (a[k] % 2 != 0) {
            cout << a[k] << " ";
            }
            k = 0;
        }
        else {
            if (a[k] % 2 != 0) {
            cout << a[k] << " ";
            }
        k++;
        }
    }

}