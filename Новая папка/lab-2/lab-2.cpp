#include<iostream>
#include<ctime>
#include <windows.h>
const int n=11;
using namespace std;
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int temp;
    int p=0;
    int q=0;
    srand(time(NULL));
    setlocale(LC_ALL,"RU");
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
    }
    while((p>=q)or(p<1)or(q>n)){
        cout<<"Введите номера границы, по которой нужно перевернуть массив"<<endl;;
        cin>>p;
        cin>>q;
    }
    p--;
    q--;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    while(p<q){
        temp=a[p];
        a[p]=a[q];
        a[q]=temp;
        p++;
        q--;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}