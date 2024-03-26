#include <iostream> 
#include <string> 
using namespace std; 

void createTable(string& podstroka, int d[]) { 
    int Q = podstroka.length(); 
    for (int i = 0; i < 256; i++) { 
        d[i] = Q; 
    } 
    for (int i = 0; i < Q - 1; i++) { 
        d[(unsigned char)podstroka[i]] = Q - i - 1; 
    } 
} 
    int BoerMur(string& stroka, string& podstroka) { 
    int N1 = stroka.length(); 
    int N2 = podstroka.length(); 
    int d[256]; 
    createTable(podstroka, d); 
    bool f = false; 
    for (int i = N2 - 1; i < N1; i += d[(unsigned char)stroka[i]]) { 
            int k = 0; 
        while ((k < N2) && (podstroka[N2 - 1 - k] == stroka[i - k])) 
        { 
            k++; 
        } 
        if (k == N2) {
            f = true; 
            return i-N2+1; 
        } 
    } 
    if (!f) { 
        return -1; 
    } 
} 

int main() { 
system("chcp 1251>NULL"); 
string str; 
string substr; 
cout << "¬ведите исходную строку: "; 
getline(cin, str); 
cout << "¬ведите подстроку, которую нужно найти: "; 
getline(cin, substr); 
int i = BoerMur(str, substr); 
if (i != -1) { 
cout << "ќбраз подстроки в строке найдет на элементе с номером : " << i+1; 
} 
else cout << "ќбраз не найден!"; 
return 0; 
} 