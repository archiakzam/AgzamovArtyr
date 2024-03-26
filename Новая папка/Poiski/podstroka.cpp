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
cout << "Введите строку: "; 
getline(cin, str); 
cout << "Введите подстроку: "; 
getline(cin, substr); 
int j= strSearch(str, substr); 
    if (j != -1) { 
        cout << "Номер элемента, с которого строка совпала с подстрокой: " << j+1; 
    } 
    else cout << "Подстрока не найдена"; 
    return 0; 
} 