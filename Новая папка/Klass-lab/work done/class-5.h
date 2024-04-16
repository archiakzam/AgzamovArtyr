#pragma once
#include <vector>
#include<iostream>
#include<string>
using namespace std;
class Object {
public:
	virtual void print() = 0;
};
class person:public Object{
protected:
    string name;
    int age;
public:
    person() {age = 0;name = "";}
    person(string name, int age){
        this->name= name;
        this->age=age;
        cout<<"Constructor person"<<endl<<endl;
    }
    person(const person& Person){
        this-> name =Person.name;
        this-> age= Person.age;
    }
    ~person(){
        cout<<"Constructor person"<<endl<<endl;
    }
    virtual void SetName(string name){
        this->name=name;
    }
    virtual void SetAge(int age){
        this->age=age;
    }
    virtual string get_name() {
        return name;
    }

    virtual int get_age() {
        return age;
    }
    void print() override {
		cout << this->name << "name" << endl;
		cout << this->age << " age" << endl;
	}
    friend istream& operator >>(istream& is, person& per) {
		cout << "name: ";
		getline(is, per.name);
		cout << "enter age: ";
		(is >> per.age).ignore();
		return is;
	}

	friend ostream& operator <<(ostream& os, person& stud) {
		cout << " name: " << stud.name << endl;

		cout << " age: " << stud.age << endl;
		return os;
	}

};
class student:public person{
private:
    string subject;
    int grade;
    friend ostream& operator <<(ostream& out, const student & Student);
    friend istream& operator >>(istream& in, const student& Student);
public:
    student() {subject = "";grade = 0;age = 0;name = "";}
    student(string name, int age, string subject, int grade) : person(name, age){
        this->subject= subject;
        this->grade=grade;
        this->name=name;
        this->age=age;
        cout<<"Constructor student"<<endl<<endl;
    }
    student(const student& Student): person(name, age){
        this->name=Student.name;
        this->age=Student.age;
        this->subject=Student.subject;
        this->grade=Student.grade;
    }
    void operator = (const student& Student){
        this->name=Student.name;
        this->age=Student.age;
        this->subject=Student.subject;
        this->grade=Student.grade;
    }
    ~student(){
        cout<<"destructor student"<<endl<<endl;
    }
    void SetSubject(string subject){
        this->subject=subject;
    }
    void SetGrade(int grade){
        this->grade=grade;
    }
    string get_subject(){
        return subject;
    }
    int get_grade(){
        return grade;
    }
    void check_grade(){
        if (grade<3){
            cout<<"student "<<name<<" has unsatisfactory grade in " << subject << endl;
        }
        else{
            cout << "Student " << name << " has passed " << subject << " with grade " << grade << endl;
        }
    }
};

ostream& operator <<(ostream& out, const student & Student){
    out << endl <<"Person:"<< Student.name<<" Age: "<<Student.age<<" Have grade "<<Student.grade<<" in subject "<<Student.subject<<endl;
    out<<endl;
    return out;
}
istream& operator >> (istream& in, student& Student){
    cout<<"Enter person, his age, subject and his grade in subject"<<endl;
    string name;
    int age;
    string subject;
    int grade;
    in>>name>>age>>subject>>grade;
    Student.SetName(name);
    Student.SetAge(age);
    Student.SetSubject(subject);
    Student.SetGrade(grade);
    return in;
}
class Vector
{
public:
	friend ostream& operator<<(ostream& out, const Vector& v) {
		if (v.size == 0) {
			cout << "\nВектор пустой" << endl;
		}
		else {
			Object** ptr = v.beg;
			for (int i = 0; i < v.cur; i++) {
				(*ptr)->print();
				ptr++;
			}
		}
		return out;
	}

	void Add(Object* ptr) {
		if (cur < size) {
			beg[cur] = ptr;
			cur++;
		}
	}


	Vector() {
		beg = 0;
		size = 0;
		cur = 0;
	}

	Vector(int lin) {
		beg = new Object * [lin];
		size = lin;
		cur = 0;
	}

	~Vector() {};
private:
	Object** beg;
	int size;
	int cur;
};
