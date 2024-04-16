#pragma once
#include <iostream>
#include <istream>
#include <vector>
using namespace std;

class Pair {
private:
    int first;
    double second;
    friend ostream& operator<<(ostream& out, const List& list);
    friend istream& operator>>(istream& in, List& list);
    friend ostream& operator<<(ostream& out, const Pair& p);
    friend class List;
public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair operator*(const Pair& p) const {
    Pair result;
    result.first = this->first * p.first;
    result.second = this->second * p.second;
    return result;
}
};
ostream& operator<<(ostream& out, const Pair& p) {
        out << p.first << " : " << p.second;
        return out;
    }

struct Node {
public:
    Pair data;
    Node* next;
    Node* prev;

};  

class List {
private:
    int size;
    Node* head;
    Node* tail;
public:
    void push_back(const Pair& data){
        Node* new_node = new Node;
        new_node->data=data;
        new_node->next=nullptr;
        if(this->head==nullptr)
        {
            this->head=new_node;
            this->tail=new_node;
            
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail=new_node;
        }
        this->size++;
    }
    void push_front(const Pair& data){
        Node* new_node = new Node;
        new_node->data=data;
        if(this->head==nullptr)
        {
            this->head=new_node;
            this->tail=new_node;
            this->size++;
            
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head=new_node;
            this->size++;
            
        }

    }
    Pair front(){
        return this->head->data;
    }
    Pair back(){
        return this->tail->data;
    }
    Pair pop_back(){
    Pair temp;
    if(this->tail != nullptr) {
        Node* current_node = this->tail;
        tail = current_node->prev;
        temp = current_node->data;
        tail->next = nullptr;
        delete current_node;
        this->size--;
    }
    return temp;
}
    
    Pair pop_front(){
        Pair temp;
        if(this->head!=nullptr){
            Node * current_node= this->head;
            head=current_node->next;
            temp=current_node->data;
            head->prev=nullptr;
            this->size--;
        }
        return temp;
    }
    bool is_empty(){
        return this->size==0;
    }
    List& operator = (const List& list){
        cout<<"Operator ="<<endl;
        if(this == &list){
            return *this;
        }
        while (head!=nullptr){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        size =0;
        Node* current_node=list.head;
        while(current_node!=nullptr){
            push_back(current_node->data);
            current_node=current_node->next;
        }
        
        return *this;
    }
    Pair& operator [](int index){
        if(index <this->size&&index>=0){
            Node* current_node = this->head;
            for(int i=0;i!=index;i++){
                current_node=current_node->next;
            }
            return current_node->data;
        }
        else{
            cerr<<"index out of range";
            exit(0);
        }
    }
    int operator () (){
        return this->size;
    }
    List operator * (List& list){
        int temp_size;
        if(this->size>list.size){
            temp_size=list.size;
        }
        else
        {
            temp_size=this->size;
        }
        List temp(temp_size,Pair(0, 0));
        for(int i=0;i<temp_size;i++){
            temp[i]=(*this)[i]*list[i];
        }
        return temp;
    }
    List(int size, const Pair& data) {
    this->size = size;
    if (size > 0) {
        head = new Node;
        head->data = data;
        tail = head;
        for (int i = 1; i < size; ++i) {
            Node* newNode = new Node;
            newNode->data = data;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        tail->next = nullptr;
    } else {
        head = nullptr;
        tail = nullptr;
    }
}
    List(const List& list)
    {
        this->head=nullptr;
        this->tail=nullptr;
        this->size=0;
        Node* current_node=list.head;
        while(current_node!=nullptr){
            push_back(current_node->data);
            current_node=current_node->next;
        }
        
    };
    List(int size){
        this->size=size;
        if(size>0){
            Node* node = new Node;
            this->head=node;
            this->tail=node;
            for(int i=1;i<size; i++){
                Node* newNode = new Node;
                tail->next = newNode;
                newNode->prev = tail;
                tail=newNode;
            }
            tail->next=nullptr;
        }
        else
        {
            this->head=nullptr;
            this->tail=nullptr;
        }
        
    };
    ~List()
    {
        Node* current_node=head;
        while(current_node!=nullptr){
            Node* next=current_node->next;
            delete current_node;
            current_node=next;
            }
        head=nullptr;
    };


    friend ostream& operator<<(ostream& out, const List& list) {
        out << "Elements of list:" << endl;
        Node* current = list.head;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        out << endl << "End of list" << endl;
        return out;
    }

    friend istream& operator>>(istream& in, List& list) {
        Node* current = list.head;
        cout << "Enter elements of the list:" << endl;
        while (current != nullptr) {
            in >> current->data.first >> current->data.second;
            current = current->next;
        }
        cout << "End of input" << endl;
        return in;
    }
};
    

