#include <math.h>    
#include <iostream>  
#include <ctime>
#include <windows.h>
using namespace std;
int** fmas(int n); 
int** fmas2(int n,int ** arr);

int** fmas(int n)
{
    srand(time(NULL));
    int ** arr = new int*[n]; 
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 100; 
        }
    }
    return arr;
}
int** fmas2(int n,int ** arr){
    for(int i=n-1;i>0;i--){
        for(int j=n-1;j>i;j--){
            if (arr[j][j]>arr[j-1][j-1]){
                int m=arr[j][j];
                arr[j][j]=arr[j-1][j-1];
                arr[j-1][j-1]=m;
            }
        }
    }
    return arr;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ru"); 
    int n;   
    cout << "Введите размер квадратной матрицы:" << endl;
    cin >> n;
    while (n <= 0)
    {
        cout << "Вы ввели неверно. Повторите ввод:" << endl;
        cin >> n;
    }
int** arr = fmas(n);
cout << "Матрица:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl << endl << endl;
    }
    int** arr2 = fmas2(n, arr);
    cout << "Измененный массив" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl << endl << endl;
    }
}