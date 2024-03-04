#include<iostream>
#include<string.h>
#include <windows.h>
using namespace std;
string* deletefroma(string *a,int &N){
    int count=0;
    for (int i = 0; i < N; i++){
        if(a[i][0] == 'A' or a[i][0] == 'a'){
            string tmp = a[count]; 
            a[count] = a[i];
            a[i] = tmp;
            count++;          
        }
    }
    N = N - count; //определим длину нового массива
    string *result = new string[N];
    for (unsigned i = 0; i < N; i++)
        result[i] = a[i + count];
    
    return result;
    
}


int main(){
    setlocale(LC_ALL,"RU");
    system("CLS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N=0;
    cout<<"¬ведите размер массива строк ";
    while (N<=0) cin>>N;
    cout<<endl;
    string *a=new string[N];
    for(int i=0;i<N;i++){
        string fl="";
        cout<<"¬ведите строку є"<<i+1<<endl;
        while(fl==""){
            getline(cin,fl);
        }
        a[i]=fl;
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<a[i]<<endl;
    }
    cout<<endl;
    string *arr = deletefroma(a, N);
    for (unsigned i = 0; i < N; i++) {
        cout << arr[i] <<endl;
    }
    delete[] arr;
    delete[] a;
    return 0;
}

