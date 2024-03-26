#include <iostream> 
#include <string> 
using namespace std; 

void preffunc(int* d, string& podstroka) { 
    d[0] = 0; 
    int j = 0; 
    int i = 1; 
    while (i < podstroka.length()) { 
        if (podstroka[j] == podstroka[i]) { 
            d[i] = j + 1; 
            i++; 
            j++; 
        } 
        else { 
            if (j == 0) { 
                d[i] = 0; 
                i++; 
            } 
            else { 
                j = d[j - 1]; 
            } 
        } 
    } 
} 

int KMP(string& stroka, string& podstroka) { 
    int* d = new int[podstroka.length()]; 
    preffunc(d, podstroka); 
    int i = 0; 
    int j = 0; 
    bool f = false; 
    while (i < stroka.length()) { 
        if (podstroka[j] == stroka[i]) { 
            i++; 
            j++; 
        } 
        if (j == podstroka.length()) { 
            f = true; 
            return i - podstroka.length(); 
        } 
        else if (i < stroka.length() && podstroka[j] != stroka[i]) { 
            if (j == 0) { 
                i++; 
            } 
            else j = d[j - 1]; 
        } 
    } 
    if (!f) { 
        return -1; 
    } 
    delete[] d; 
} 
int main() { 
    system("chcp 1251>NULL"); 
    string str; 
    string substr; 
    cout << "������� �������� ������: "; 
    getline(cin, str); 
    cout << "������� ���������, ������ ����� �����: "; 
    getline(cin, substr); 
    int i = KMP(str, substr); 
    if (i != -1) { 
        cout << "����� ��������� � ������ ������ �� �������: " << i; 
    } 
    else cout << "����� �� ������!"; 
    return 0; 
} 