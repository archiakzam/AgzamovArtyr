#include<iostream>
#include<string>
#include <vector>
#include "class-5.h"
using namespace std;
int main(){
    student chel("Vanya",18,"math",4);
    cout<<chel;
    chel.SetGrade(2);
    chel.check_grade();
    cin>>chel;
    cout<<chel;
    
    person Person1("Alice", 25);
    student Student1("Bob", 20, "Math", 4);

   
    Student1.check_grade();
    return 0;
}