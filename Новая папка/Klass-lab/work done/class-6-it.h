#pragma once
#include <iostream>
#include <vector>
#include "class-6.h"
using namespace std;

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