#include"class-9-error.h"
#include"class-9.h"
#include<iostream>
#include<string>
using namespace std;


int main(){
    system("chcp 1251>null");
    system("cls");

    List sp1,sp2;
    int count,x,index,h;
    cout << "Enter element count: ";
    cin >> count;
    try
    {
        if (count < 1) throw error_empty();
        cout << "Enter element of list: ";
        for (int i = 0; i < count; ++i)
        {
            cin >> x;
            sp1.push_back(x);
        }
        cout << "Enter index of list number 1 for calling: ";
        cin >> index;
        cout << "Enter element with this index: " << sp1[index] << endl;
        cout << "Enter index of right element of list sp1: ";
        cin >> h;
        cout << "element with this index: " << sp1+h << endl;
        cout << "Size of lsit : " << sp1() << endl;
        cout << "Enter count of element of list number 2: ";
        cin >> count;
        if (count < 1) throw error_empty();
        cout << "Enter element of list: ";
        for (int i = 0; i < count; ++i)
        {
            cin >> x;
            sp2.push_back(x);
        }
        sp1* sp2;
        cout << "List obtained by multiplying two lists: ";
        cout<<sp1<<endl;

    }
    catch (Error& a)
    {
        a.what();
    }
    return 0;
}
