#include <string>
#include <iostream>
using namespace std;
string sorting(string str)
{
    int k=0;
    for(int i=0;i<str.length();i++) if(str[i]==' ') k++;
    string words[k+1];
    k=0;
    int wrd_start=0,wrd_end=0;
    for(int i=0;i<str.length();i++){
        if((str[i]==' ') or (i==(str.length()-1))){
            wrd_end=i;
            for(int j=wrd_start;j<wrd_end;j++) words[k]+=str[j];
            k++;
            wrd_start=(wrd_end+1);
        }
    }
    string tmp="";
    for(int i=0;i<k;i++){
        for(int j=i;j<k;j++){
            if(words[i]>words[j]){
                tmp=words[i];
                words[i]=words[j];
                words[j]=tmp;
            }
        }

    }
    str="";
    for(int i=0;i<k;i++) str+=(words[i]+" ");
    return str;
}
int main()
{
    system("chcp 1251");
    string str;
    cout<<"¬ведите строку:";
    getline(cin,str);
    str=sorting(str);
    cout << str;
    return 0;
}