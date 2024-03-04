#include <iostream>
#include <stdarg.h>
using namespace std;
const int n=4;
int M[n];
unsigned int nod(unsigned int a, unsigned int b) {
  if (a % b == 0)
    return b;
  if (b % a == 0)
    return a;
  if (a > b)
    return nod(a%b, b);
  return nod(a, b%a);
}
unsigned int nok(unsigned int a, unsigned int b) {
  return (a*b)/nod(a,b);
}
int NoKk (int k, ...)
{

    int s=0;
    va_list arg;
    va_start(arg, k);

    for(int i=0; i<k;++i){
        M[i]= va_arg(arg, int);
    }
    va_end(arg);
    for(int i=1;i<k;i++){
        s=nok(M[i-1],M[i]);
        M[i]=s;
    }
    return s;
}
int main(){
    cout<<NoKk(3,5,4,6)<<endl; //находит сумму 1+2+3+4
    return 0;
}