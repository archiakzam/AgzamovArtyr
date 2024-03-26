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
    cout << "������� ���-�� �������� � �������: "; 
    cin >> N; 
    int* a = new int[N]; 
    for (int i = 0; i < N; i++) { 
        cout << "������� " << i + 1 << " �������: "; 
        cin >> a[i]; 
    } 
    cout << "�������� ������: "; 
    for (int i = 0; i < N; i++) { 
        cout << a[i] << ' '; 
    } 
    cout << endl; 
    int key; 
    cout << "������� key: "; 
    cin >> key; 
    int i = binSearch(a, N, key); 
    if (i != 0) { 
        cout << "����� ��������, ������� ������ � key: " << i + 1; 
    } 
    else cout << "�������� ���"; 
    return 0; 
} 