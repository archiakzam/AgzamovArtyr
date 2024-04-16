#include<iostream>
#include "class-3.h"
using namespace std;
int main(){
    pairs a(1,5.2);
    pairs b(2,1.2);
    double c1=54.2;
    int c2=4;
    a=a - b;
    a.PrintPair();
    a=a+c1;
    a.PrintPair();
    a=a+c2;
    a.PrintPair();
    return 0;
}