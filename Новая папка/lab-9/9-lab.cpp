#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    ifstream in("f1.txt");
    ofstream out("f2.txt");
    string line;
    while (getline(in, line))
    {
        bool hasEquals = true;
        int l=0;
        for(int i=0;i<line.length();i++) if(line[i]==' ') l++;
        string *word=new string[l+1];
        int k=0;
        int wrd_start=0,wrd_end=0;
        for(int i=0;i<line.length();i++){
            if((line[i]==' ') or (i==(line.length()-1))){
                wrd_end=i;
                for(int j=wrd_start;j<wrd_end;j++) word[k]+=line[j];
                k++;
                wrd_start=(wrd_end+1);
            }
        }
        for(int i=0;i<l;i++) {
            for (int j=i+1;j<l;j++){
                if(word[i]==word[j])hasEquals=false;
                }
        }
        if (hasEquals) out << line << endl;
        delete[] word;

    }
    ifstream in1("f2.txt");
    string consonants("AEIOUYaeiouy");
    int consCount=0;
    string line1;
    getline(in1,line1);

    for(auto it=line1.begin(); it!=line1.end(); it++)
        if (consonants.find(*it)!=string::npos)
            consCount++;
    cout << "Consonants count: " << consCount;
    in.close();
    out.close();
    return 0;
}