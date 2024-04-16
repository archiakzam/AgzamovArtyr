#pragma once

#include <iostream>
#include <vector>
using namespace std;


struct Node {
public:
    int data;
    Node* next;
    Node* prev;

};
class Iterator
{
private:
    friend class List;
    
    Node* elem;
public:
    Iterator()
    {
        this->elem=nullptr;
    }
    Iterator(const Iterator& iterator)
    {
        this->elem=iterator.elem;
    }
    Iterator& operator = (const Iterator& iterator)
    {
        this->elem=iterator.elem;
        return *this;
    }
    bool operator ==( const Iterator& iterator)
    {
        return this->elem==iterator.elem;
    }
    bool operator !=( const Iterator& iterator)
    {
        return this->elem!=iterator.elem;
    }
    Iterator& operator++(){
        this-> elem= this->elem->next;
        return *this;
    }
    Iterator& operator--(){
        this-> elem= this->elem->prev;
        return *this;
    }
    Iterator& operator+(const int number)const{
        Iterator temp(*this);
        for(int i=0;i<number;i++){
        temp.elem= temp.elem->next;
        }
        return temp;
    }
    Iterator& operator-(const int number)const{
        Iterator temp(*this);
        for(int i=0;i<number;i++){
        temp.elem= temp.elem->prev;
        }
        return temp;
    }
    int& operator* ()
    {
        return this->elem->data;
    }
};

class List {
private:
    int size;
    Node* head;
    Node* tail;
    friend ostream& operator<<(ostream& out, const List& list);
    friend istream& operator >> (istream& in, const List& list);
    Iterator begin;
    Iterator end;
public:
    void push_back(int data){
        Node* new_node = new Node;
        new_node->data=data;
        new_node->next=nullptr;
        if(this->head==nullptr)
        {
            this->head=new_node;
            this->tail=new_node;
            this->begin.elem=this->head;
            this->end.elem=this->tail;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail=new_node;
        }
        this->size++;
    }
    void push_front(int data){
        Node* new_node = new Node;
        new_node->data=data;
        if(this->head==nullptr)
        {
            this->head=new_node;
            this->tail=new_node;
            this->size++;
            this->begin.elem=this->head;
            this->end.elem=this->tail;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head=new_node;
            this->size++;
            this->begin.elem=this->head;
        }

    }
    int front(){
        return this->head->data;
    }
    int back(){
        return this->tail->data;
    }
    int pop_back(){
        int temp;
        if(this->tail!=nullptr){
            Node * current_node= this->tail;
            tail=current_node->prev;
            temp=current_node->data;
            tail->next=nullptr;
            this->size--;
        }
        return temp;
    }
    int pop_front(){
        int temp;
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
        this->begin=list.begin;
        this->end=list.end;
        return *this;
    }
    int& operator [](int index){
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
        List temp(temp_size,0);
        for(int i=0;i<temp_size;i++){
            temp[i]=(*this)[i]*list[i];
        }
        return temp;
    }
    Iterator first(){
        return this->begin;
    }
    Iterator last(){
        return this->end;
    }
    List(int size,int data){
        this->size=size;
        if(size>0){
            Node* node = new Node;
            node->data=data;
            this->head=node;
            this->tail=node;
            for(int i=1;i<size; i++){
                Node* newNode = new Node;
                newNode->data=data;
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
        this->begin.elem=this->head;
        this->end.elem=this->tail;
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
        this->begin.elem=this->head;
        this->end.elem=this->tail;
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
        this->begin.elem=this->head;
        this->end.elem=this->tail;
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


};
    ostream& operator<<(ostream& out, const List& list){
        out <<endl<< "Elements of list"<<endl;
        Node* current_node = list.head;
        while (current_node!=nullptr)
        {
            out<<current_node->data<< " ";
            current_node=current_node->next;
        }
        out<<endl<<"conclusion end"<<endl;
        return out;
    }
    istream& operator >> (istream& in, const List& list){

        cout<<endl<<"Enter element of list"<<endl;
        Node* current_node=list.head;
        while (current_node!=nullptr){
            in>>current_node->data;
            current_node=current_node->next;
        }
        cout<<endl<<"Enter element stop"<<endl;
        return in;
    }

