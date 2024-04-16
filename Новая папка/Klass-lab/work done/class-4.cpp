#include<iostream>
#include<string>
#include "class-4.h"
using namespace std;
int main(){
    student chel("Vanya",18,"math",4);
    cout<<chel;
    chel.SetGrade(2);
    chel.check_grade();
    cin>>chel;
    cout<<chel;
    chel.check_grade();
    return 0;

}