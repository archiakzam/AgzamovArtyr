#include<iostream>
#include<string.h>
#include <windows.h>
#include<fstream>
using namespace std;
struct books{
    string imya;    
    string avtors;  
    int age;        
    int kolvo;      
    void enter_info(string i, string a, int ag, int k) {
            imya = i;
            avtors = a;
            age = ag;
            kolvo = k;
    }
};


int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("CLS");
    system("chcp 1251");
    int N;
    cout << "¬ведите  N больше 4: ";
    cin >> N;
    books mass[50];
    for(int j=0;j<N;j++){
        string u, a;
        int ag,k;
        cout<<"¬ведите название книги, им€ автора, дату выхода, кол-во страниц"<<endl;
        cin>>u>>a>>ag>>k;
        mass[j].enter_info(u, a, ag, k);
    }
    for(int j=0; j<3;j++){
        for(int ij=0;ij<N;ij++){
            mass[ij]=mass[ij+1]; 
        }
        N--;
    }
    cout<<"ѕервые 3 книги удалены. оставшиес€ книги -"<<endl;
    for(int j=0;j<N;j++){
        cout<<mass[j].imya<<" "<<mass[j].avtors<<" "<<mass[j].age<<" "<<mass[j].kolvo<<endl;
    }
    bool f=false;
    int nind;
    string nimya;
    cout<<"¬ведите название книги, перед которой нужно добавить новую"<<endl;
    cin>>nimya;
    for(int j=0;j<N;j++){
        if(mass[j].imya==nimya){
            nind=j;
            f=true;
        }
    }
    if (f==true){
        for(int j=N;j>nind;j--){
            mass[j]=mass[j-1];
        }
        string i1, a1;
        int ag1,k1;
        cout<<"¬ведите название новой книги, им€ автора, дату выхода, кол-во страниц"<<endl;
        cin>>i1>>a1>>ag1>>k1;
        mass[nind].enter_info(i1,a1,ag1,k1);
        N++;
    }
    ofstream f1("f1.txt");
    for(int j=0;j<N;j++){
        f1<<mass[j].imya<<" "<<mass[j].avtors<<" "<<mass[j].age<<" "<<mass[j].kolvo<<endl;
    }
    f1.close();
    cout<<"книги -"<<endl;
    for(int j=0;j<N;j++){
        cout<<mass[j].imya<<" "<<mass[j].avtors<<" "<<mass[j].age<<" "<<mass[j].kolvo<<endl;
    }
    system("PAUSE");
    return 0;
}