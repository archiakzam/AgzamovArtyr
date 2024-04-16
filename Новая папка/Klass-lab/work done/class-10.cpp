#include <iostream> 
#include<ctime>
#include <fstream> 

using namespace std; 

 

class Pair { 

private: 

    int x; 

    double y; 

public: 

    Pair() { 

        this->x = 0; 

        this->y = 0; 

         

    } 

    Pair(int i, double j) { 

        this->x = i; 

        this->y = j; 

        cout << "The constructor is called with the parameters: " << this << endl; 

        cout << "X = " << this->x << '\t' << "Y = " << this->y << endl << endl; 

    } 

    Pair(const Pair& d) { 

        this->x = d.x; 

        this->y = d.y; 

        cout << "The copy constructor is called: " << this << endl; 

        cout << "X = " << this->x << '\t' << "Y = " << this->y << endl << endl; 

    } 

    double diff() { 

        return this->x - this->y; 

    } 

    void setX(int b) { 

        this->x = b; 

    } 

    void setY(double a) { 

        this->y = a; 

    } 

    int returnX() { 

        return this->x; 

    } 

    double returnY() { 

        return this->y; 

    } 

     

    void dobavlenieConst(int j) { 

        cout << "К " << this->x << " adding const " << j << ": " << endl; 

        this->x = x + j; 

    } 

    void dobavlenieConst(double i) { 

        cout << "К " << this->y << " adding const " << i << ": " << endl; 

        this->y = y + i; 

    } 

    void operator=(const Pair& a) { 

        this->x = a.x; 

        this->y = a.y; 

    } 

    void operator -(const Pair& a) { 

        this->x = x - a.x; 

        this->y = y - a.y; 

    } 

    void operator +(int j) { 

        cout << "К " << this->x << " adding const " << j << ": " << endl; 

        this->x = x + j; 

    } 

    void operator +(double k) { 

        cout << "К " << this->y << " adding const " << k << ": " << endl; 

        this->y = y + k; 

    } 

    ~Pair() { 

        cout << "Destructor called: " << this << endl; 

    } 

    friend istream& operator >> (istream& is, Pair& p) { 

        cout << "Operator >> operator overload caused  " << endl << endl; 

        cout << "enter int x : "; 

        is >> p.x; 

        cout << "Enter double y: "; 

        is >> p.y; 

        cout << "overload end" << endl << endl; 

        return is; 

 

    } 

    friend ostream& operator << (ostream& os, const Pair& p) { 

        cout << "Operator << operator overload caused " << endl << endl; 

        os << p.x << " : " << p.y << endl << endl; 

        cout << "overload end" << endl << endl; 

        return os; 

    } 

    friend fstream& operator << (fstream& fout, const Pair& p) { 

        fout << p.x << " : " << p.y; 

        return fout; 

 

    } 

    friend fstream& operator >> (fstream& fin, Pair& p) { 

        char q; 

        fin >> p.x; 

        fin >> q; 

        fin >> p.y; 

        return fin; 

 

    } 

 

}; 

 

Pair& randomPair(Pair& p) { 

    p.setX(rand() % 10); 

    p.setY((double)(rand() % 1000) / (double)(rand() % 100) + 1); 

    return p; 

} 

 

int make_file(string f_name) { 

    fstream stream(f_name + ".txt", ios::out | ios::trunc); 

    if (!stream) { 

        cout << "Error file open"; 

        return -1; 

    } 

    int n; 

    cout << "Enter the number of elements in the file: "; 

    cin >> n; 

    for (int i = 0; i < n; i++) { 

        Pair p; 

        randomPair(p); 

        stream << p << endl; 

    } 

    stream.close(); 

    return n; 

} 

int print_file(string f_name) { 

    fstream stream(f_name + ".txt", ios::in); 

    if (!stream) { 

        cout << "Error file open"; 

        return -1; 

    } 

    Pair p;  

    int i = 0; 

    while (stream >> p) { 

        cout << p << endl; 

        i++; 

    } 

    stream.close(); 

    return i; 

} 

 

int del_file(const char* f_name, int k) { 

    fstream temp("temp.txt", ios::out); 

    fstream stream(f_name, ios::in); 

    if (!stream) { 

        cout << "Error file open"; 

        return -1; 

    } 

    int i = 0; 

    Pair p; 

    while (stream >> p) { 

        if (p.returnX() >= k && p.returnY() >= k) { 

            temp << p << endl; 

            i++; 

            

        } 

       

    } 

    stream.close(); 

    temp.close(); 

    remove(f_name); 

    rename("temp.txt", f_name); 

    return i; 

} 

 

int change_file(const char* f_name, int k, int L) { 

    fstream temp("temp.txt", ios::out); 

    fstream stream(f_name, ios::in); 

    if (!stream) { 

        cout << "Error file open"; 

        return -1; 

    } 

    Pair p; 

    int i = 0; 

    while (stream >> p) { 

        if (p.returnX() == k || p.returnY() == k) { 

            p.setX(p.returnX() + L); 

            p.setY(p.returnY() + L); 

            i++; 

        } 

        temp << p << endl; 

     

    } 

    stream.close(); 

    temp.close(); 

    remove(f_name); 

    rename("temp.txt", f_name); 

    return i; 

} 

int add_file(const char* f_name, int index, int K) { 

    fstream temp("temp.txt", ios::out); 

    fstream stream(f_name, ios::in); 

    if (!stream) { 

        cout << "Error file open"; 

        return -1; 

    } 

    Pair p; 

    int i = 0; 

    while (stream >> p) { 

        temp << p << endl; 

        i++; 

        if (i == index) { 

            for (int j = 0; j < K; j++) { 

                cout << " enter new value: " << endl; 

                cin >> p; 

                temp << p << endl; 

            } 

        } 

    } 

    stream.close(); 

    temp.close(); 

    remove(f_name); 

    rename("temp.txt", f_name); 

    return i; 

} 

 

int main() { 
    system("chcp 1251>null");
    system("cls");
    srand(time(NULL)); 

    string f_name; 

    int с, size = 0; 

    do { 

        cout << "\n1. create file"; 

        cout << "\n2. export file element"; 

        cout << "\n3. Delete records less than a certain value"; 

        cout << "\n4. Increment all records with a given value by the number K"; 

        cout << "\n5. Add K records after an element with a given number"; 

        cout << "\n0. Exit the program\n"; 

        cin >> с; 

        switch (с) { 

        case 0: 

            cout << "close"; break; 

        case 1: 

            cout << "Enter file name: "; 

            cin >> f_name; 

            size = make_file(f_name); 

            if (size < 0) cout << "File not created( "; 

            break; 

        case 2: 

            cout << "enter file name "; 

            cin >> f_name; 

            size = print_file(f_name); 

            if (size == 0) cout << "file empty "; 

            if (size < 0) cout << "size < 0 "; 

            break; 

        case 3: 

            cout << "enter file name: "; 

            cin >> f_name; 

            int k; 

            cout << "Enter min element: "; 

            cin >> k; 

            f_name += ".txt"; 

            size = del_file(f_name.c_str(), k);  

            if (size < 0) cout << "size < 0  "; 

            break; 

        case 4: 

            cout << "Enter file name "; 

            cin >> f_name; 

            int value; 

            cout << "Enter the value to change: "; 

            cin >> value; 

            int K; 

            cout << "Enter K: "; 

            cin >> K; 

            f_name += ".txt"; 

            size = change_file(f_name.c_str(), value, K);  

            if (size < 0) cout << "size < 0 "; 

            break; 

        case 5: 

            cout << "Enter file name: "; 

            cin >> f_name; 

            int index; 

            cout << "enter number element: "; 

            cin >> index; 

            cout << "Enter К: "; 

            do 

            { 

                cin >> K; 

            } while (K < 1); 

            f_name += ".txt"; 

            size = add_file(f_name.c_str(), index, K);  

            if (size < 0) cout << "size < 0"; 

            break; 

        default: 

            cout << " we dont have this"; 

            break; 

        } 

    } while (с != 0); 

    return 0; 

} 