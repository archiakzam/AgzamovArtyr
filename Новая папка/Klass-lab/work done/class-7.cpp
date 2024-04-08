#include <iostream>
#include <vector>
#include "class-7.h"
using namespace std;

int main() {
    Pair pair1(2,5.4);
    Pair pair2(4,5.1);
    List list1(2,pair1);
    list1.push_front(pair2);
    cout<<list1<<endl;
    return 0;
}