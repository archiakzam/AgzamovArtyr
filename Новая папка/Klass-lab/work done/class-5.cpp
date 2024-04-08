#include<iostream>
#include<string>
#include <vector>
#include "class-5.h"
using namespace std;
int main(){
    system("chcp 1251>null");

	Vector vec(4);
	person per;
	student stud;

	cin >> per;
	cout << per;

	cin >> stud;
	cout << stud;

	Object* p = &per;
	vec.Add(p);

	p = &stud;
	vec.Add(p);

	cout << vec;

	return 0;
}
