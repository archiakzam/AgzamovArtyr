#include <iostream> 

using namespace std;

class Salary {
	string name;
	double payment;
	int bonus;

public:
	Salary() {
		name = "Base name";
		payment = 0;
		bonus = 0;
		cout << "������ ����������� " << this << endl;
	}
	Salary(string name, double payment, int bonus) {
		this->name = name;
		this->payment = payment;
		this->bonus = bonus;
		cout << "������ ����������� " << this << endl;
	}
	Salary(const Salary& a) {
		this->name = a.name;
		this->payment = a.payment;
		this->bonus = a.bonus;
		cout << "������ ����������� ����������� " << this << endl;
	}
	~Salary() {
		cout << "������ ���������� " << this << endl;
	}
	void Print() {
		cout << "���: " << name << "  ��������: " << payment << "  ������: " << bonus << endl;
	}
	void setpay(double pay) {
		this->payment = pay;
	}
	void setname(string name) {
		this->name = name;
	}
	void setbonus(int bonus) {
		this->bonus = bonus;
	}
	string getname() {
		return name;
	}
	double getpay() {
		return payment;
	}
	int getbonus() {
		return bonus;
	}

};

int main() {
	system("chcp 1251>NULL"); 
	Salary emp1;
	emp1.setname("�������� ������� ����������� ");
	emp1.setpay(100000);
	emp1.setbonus(20);
	emp1.Print();
	Salary emp2("������ �������� ", 200000, 30);
	emp2.Print();
	Salary emp3(emp2);
	emp3.Print();
	int bonus3 = emp3.getbonus();
	cout << "������ ������� " << bonus3 << endl;

}
