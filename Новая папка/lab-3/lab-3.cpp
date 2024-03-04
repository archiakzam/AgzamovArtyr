#include<iostream>
#include<ctime>
#include <windows.h>
const int n=11;
using namespace std;
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int temp;
    int k=0;
    srand(time(NULL));
    setlocale(LC_ALL,"RU");
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
    }
    while(k<1){
        cout<<"¬ведите, сколько раз сдвинуть массив влево"<<endl;
        cin>>k;
    }
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        
    }
    cout<<endl;
    for(int i=0;i<k;i++){
        temp=a[0];
        for(int j=0;j<n-1;j++){
            a[j]=a[j+1];
        }
        a[n-1]=temp;
    }
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}