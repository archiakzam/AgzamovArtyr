#include <iostream>
#include <vector>
#include<ctime>
#include "class-6.h"

using namespace std;

int main() {
    system("chcp 1251>null");
    system("cls");
    srand(time(NULL));
    List list1(10,0);
    cout<<list1<<endl;
    for(int i;i<list1();i++){
        list1[i]=rand()%(100+1)-50;
    }
    cout<<endl<<list1<<endl;
    List list2(list1);
    cout<<endl<<list2<<endl;
    list2.push_back(0);
    list2.pop_back();
    cout<<endl<<list2<<endl;
    List list3(6);
    cin>>list3;
    cout<<endl<<list3<<endl;
    List list4 = list3*list2;
    cout<<endl<<list4<<endl;

    for (Iterator it=list1.first(); it!=list1.last();it=it+1){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
