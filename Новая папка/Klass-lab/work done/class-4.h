#pragma once
#include<iostream>
#include<string>
using namespace std;
class person{
protected:
    string name;
    int age;
public:
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
    void SetName(string name){
        this->name=name;
    }
    void SetAge(int age){
        this->age=age;
    }
    string get_name() {
        return name;
    }

    int get_age() {
        return age;
    }
};
class student:public person{
private:
    string subject;
    int grade;
    friend ostream& operator <<(ostream& out, const student & Student);
    friend istream& operator >>(istream& in, const student& Student);
public:
    student(string name, int age, string subject, int grade) : person(name, age){
        this->subject= subject;
        this->grade=grade;
        this->name=name;
        this->age=age;
        
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