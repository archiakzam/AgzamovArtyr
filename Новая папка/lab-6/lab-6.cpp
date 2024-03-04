#include <iostream>
#include <cmath>
using namespace std;

long double fact(int N){
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

int rec(double x, double eps = 1e-10, int n = 0){
    double t = pow(x,2*n+1) / fact(2*n+1);
    if (abs(t) > eps) return rec(x,eps,n+1) + t;
    else return t;
}

int main(){
    int x=6;
    cout<<rec(x)<<endl;
    return 0;
}