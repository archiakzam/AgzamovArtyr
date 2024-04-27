#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <map>
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

    }
    Pair(const Pair& d) {
        this->x = d.x;
        this->y = d.y;
    }
    double diff() {
        return this->x - this->y;
    }
    void dobavlenieConst(int j) {
        cout << "К " << this->x << " добавляем const " << j << ": " << endl;
        this->x = x + j;
    }
    void dobavlenieConst(double i) {
        cout << "К " << this->y << " добавляем const " << i << ": " << endl;
        this->y = y + i;
    }
    void GetInfo() {
        cout << this->x << " : " << this->y << endl;
    }
    void operator=(const Pair& a) {
        this->x = a.x;
        this->y = a.y;
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
    void operator -(const Pair& a) {
        this->x = x - a.x;
        this->y = y - a.y;
    }
    void operator +(int j) {
        cout << "К " << this->x << " добавляем const " << j << ": " << endl;
        this->x = x + j;
    }
    void operator +(double k) {
        cout << "К " << this->y << " добавляем const " << k << ": " << endl;
        this->y = y + k;
    }
    Pair operator + (Pair& p) {
        x = x + p.x;
        y = y + p.y;
        return *this;
    }
    bool operator > (const Pair& other) {
        if (this->x != other.x) {
            return this->x > other.x;
        }
        else {
            return this->y > other.y;
        }
    }
    bool operator < (const Pair& other) {
        if (this->x != other.x) {
            return this->x < other.x;
        }
        else {
            return this->y < other.y;
        }
    }


    ~Pair() {

    }
    friend istream& operator >> (istream& is, Pair& p) {
        cout << "Введите первое (целое) число: ";
        is >> p.x;
        cout << "Введите второе (вещественное) число: ";
        is >> p.y;
        return is;
    }
    friend ostream& operator <<(ostream& os, const Pair& p) {
        os << p.x << " : " << p.y;
        return os;
    }
    friend bool operator ==(const Pair& a, const Pair& b) {
        if (a.x == b.x) {
            return a.x == b.x;
        }
    }
    void operator /(const int& a) {
        this->x = x / a;
    }
    friend bool operator >(const Pair& a, const Pair& b) {
        if (a.x != b.x) {
            return a.x > b.x;
        }
        else {
            return a.y > b.y;
        }
    }
    friend bool operator <(const Pair& a, const Pair& b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        else {
            return a.y < b.y;
        }
    }
};
void RandomPair(Pair& p) {
    int x = rand() % 1000;
    double y = (rand() % 1000) * 0.01;
    p = Pair(x, y);
}
void generate1(map<Pair, Pair>& my1, int size) {
    Pair qwe_1(0, 0), qwe_2(0, 0);
    for (int i = 0; i < size; i++) {
        RandomPair(qwe_1);
        RandomPair(qwe_2);
        my1[qwe_1] = qwe_2;
    }
}
ostream& operator <<(ostream& os, const pair<Pair,Pair>p) {
    os << "Ключ - " << p.first << "  Значение - " << p.second << endl;
    return os;
}
ostream& operator <<(ostream& os, const map<Pair, Pair>p) {
    map<Pair, Pair>::const_iterator It = p.begin();
    while (It != p.end()) {
        cout << *It++;
    }
    return os;
}
bool isInRange(Pair& key, Pair& l, Pair& u) {
    return key > l && key < u;
}
void remove_from_range(map<Pair, Pair>&p, Pair & l, Pair & u) {
        auto it = p.begin();
        Pair ptr;
        while (it != p.end()) {
            ptr = it->first;
            if (!isInRange(ptr, l, u)) {
                it++;
            }
            else
            {
                it = p.erase(it);
            }
        }
}
Pair minimum_pair(map<Pair, Pair>& p) {
    auto it = p.begin();
    Pair ptr;
    ptr = it->first;
    return ptr;
}

Pair maximum_pair(map<Pair, Pair>& p) {
    auto it = p.begin();
    Pair ptr;
    while (it != p.end()) {
        ptr = it->first;
        it++;
    }
    return ptr;
}
void all_sum(map<Pair, Pair>& p, Pair& key, Pair& value) {
    for (const auto& pair : p) {
        Pair asd = pair.first;
        key = key + asd;
        asd = pair.second;
        value = value + asd;
    }
}
map<Pair, Pair> add_to_all(map<Pair, Pair>& p, Pair& key, Pair& value) {
    map<Pair, Pair> ptr;
    for (const auto& pair : p) {
        Pair asd_1 = pair.first;
        Pair asd_2 = pair.second;
        ptr[asd_1 + key] = (asd_2 + value);
    }
    return ptr;
}
bool findPair(map<Pair, Pair>& p, Pair& key, Pair& value) {
    auto it = p.find(key);
    if (it != p.end()) {
        value = Pair(it->second);
        return true;
    }
    else {
        return false;
    }
}

int main() {
    system("chcp 1251>NULL");
    cout << "Введите кол-во элементов: ";
    int N;
    cin >> N;
    Pair sum_1(0, 0), sum_2(0, 0), sum_key(0, 0), sum_value(0, 0);
    map<Pair, Pair> adj;
    generate1(adj, N);
    cout << "Полученный словарь: " << endl << adj << endl << endl;
    all_sum(adj, sum_1, sum_2);
    sum_1 / adj.size();
    sum_2 / adj.size();
    cout << "Cреднее арифмитическое ключей: " << endl << sum_1 << endl << endl;
    cout<< "Cреднее арифмитическое значений: " << endl << sum_2 << endl << endl;
    adj[sum_1] = sum_2;
    cout << "Контейнер с средним арифмитическим: " << endl << adj << endl << endl;
    cout << "Введите две пары чисел, которые будут служить диапазоном удаления: " << endl;
    Pair one;
    Pair two;
    cout << "Первая пара: " << endl;
    cin >> one;
    cout << one << endl << endl;
    cout << "Вторая пара: " << endl;
    cin >> two;
    cout << two << endl << endl;
    if (one > two) {
        swap(one, two);
    }
    remove_from_range(adj, one, two);
    cout << "После удаления из диапазона: " << endl << adj << endl << endl;
    Pair max = maximum_pair(adj);
    Pair min = minimum_pair(adj);
    findPair(adj, min, sum_1);
    findPair(adj, max, sum_2);
    cout << "Минимальный элемент по ключу: " << endl;
    cout << "Ключ - " << min << "  Значение - " << sum_1 << endl << endl;
    cout << "Максимальный элемент по ключу: " << endl;
    cout << "Ключ - " << max << "  Значение - " << sum_2 << endl << endl;
    sum_key = max + min;
    sum_value = sum_1 + sum_2;
    cout << "Сумма max и min: " << endl;
    cout << "Ключ - " << sum_key << "  Значение - " << sum_value << endl << endl;
    adj = add_to_all(adj, sum_key, sum_value);
    cout << "После добавления max и min: " << endl << adj << endl << endl;
    cout << "Поиск элемента по ключу, введите ключ, по которому нужно найти элемент: " << endl;
    Pair o;
    cin >> o;
    bool find = findPair(adj, o, two);
        if (find) {
            cout << "Элемент найден: " << endl;
            cout << "Ключ - " << o << "  Значение - " << two << endl << endl;
    }
        else {
            cout << "Элемент не найден";
        }
 
}
