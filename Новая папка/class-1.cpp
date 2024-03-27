#include<iostream>
#include<cmath>

using namespace std;

class progressia{
    private:
        double first;
        int second;
    public:
        progressia(double first,int second){
            this->first=first;
            this->second=second;
        }
        void element(int j){
            int n1=j;
            double r=abs(first-second);
            double result=first +(n1-1)*r;
            cout<<"element whis index = "<<result<<endl;
        }
};

int main(){
    double first;
    int second;
    cout<<"enter first and second element:";
    cin>>first>>second;
    progressia j(first,second);
    j.element(2);
}