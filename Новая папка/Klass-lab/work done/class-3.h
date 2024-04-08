#pragma once
#include<iostream>
using namespace std;
class pairs{
private:
    int first;
    double second;
public:
    void PrintPair(){
        cout<<first<<":"<<second<<endl;
    }
    pairs(int first1, double second1){
        first=first1;
        second=second1;
    }
    pairs operator - (const pairs & other){
        return pairs(this->first-other.first,this->second-other.second);
    }
    pairs operator +(int val){
        return pairs(first+val,second);
    }
    pairs operator +(double val){
        return pairs(first,second+val);
    }
};