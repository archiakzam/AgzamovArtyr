#include <iostream> 
#include <string> 
using namespace std; 

int strSearch(string str, string substr) { 
    int d = str.length(); 
    int k = substr.length(); 
    int N = d-k; 
    for (int i = 0; i < N; i++) { 
        int j; 
        for (j = 0; j < k; j++) { 
            if (str[i + j] != substr[j]) { 
                break; 
            } 
        } 
        if (j == k) { 
            return i; 
        } 
    } 
    return -1; 
} 

int main() { 
system("chcp 1251>NULL"); 
system("cls"); 
string str; 
string substr; 
cout << "������� ������: "; 
getline(cin, str); 
cout << "������� ���������: "; 
getline(cin, substr); 
int j= strSearch(str, substr); 
    if (j != -1) { 
        cout << "����� ��������, � �������� ������ ������� � ����������: " << j+1; 
    } 
    else cout << "��������� �� �������"; 
    return 0; 
} 