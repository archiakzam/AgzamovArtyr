#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstddef>
#include <iostream>
#include <windows.h>
using namespace std;
int count(const int* arr, int len)
{
    int res = 0;
    for(int i = 0; i < len; ++i)
        if((arr[i]) >res) res=arr[i];
 
    return res;
}
 
int count(const char* str)
{
    int n, i, k, kol, max = 0, y,g,j=0;
    int p;
    i = 0;
    for (int l=0;l<strlen(str);l++)//проходимся по длине строки, и ищем пробелы, и после каждого меряем слово.
    {
    while (str[l] != ' ')
    {
        if (str[l] == ' ')
        {
            p=l;
            l++;
        }
        else
        {

            do
            {
                l++;
            } while (str[l] != ' ');    //длина слова
             kol = strlen(str)-l-p; //длина слова  //p последний пробел
            if (kol > max)
            {
                l++;
                     ///max word
                max = kol;
            }

        }

     }
    }
    for (n; n<k; n++)
    {
        cout << str[n];
    }
    cout << " - самое длинное слово" << endl;
    return max;
}
 
 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 10;
 
    int a[n];
    srand(time(NULL));
 
    cout<< "array: ";
    for(int i = 0; i < n; ++i)
    {
        a[i] = rand() % 100;
        cout << a[i] << ' ';
    }
 
    cout << "\nresult: " << count(a, n) << '\n';
 
    // 2
    char str[256];
    cout << "input string: ";
    if(!cin.getline(str, sizeof(str))) return 1;
    cout << "result: " << count(str) << '\n';
}
