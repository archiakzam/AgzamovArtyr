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
    cin>> key; 
    int i =listSearch(a, key, N); 
    if (i != 0) { 
        cout << "����� ��������, ������� ������ � key: " << i + 1; 
    } 
    else cout << "�������� ���"; 
    return 0; 
} 