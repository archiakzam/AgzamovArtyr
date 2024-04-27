#include <iostream>
#include <list>
#include <string>
#include <algorithm>
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
    bool operator > (const Pair& other){
        if (this->x != other.x) {
            return this->x > other.x;
        }
        else {
            return this->y > other.y;
        }
    }
    bool operator < (const Pair& other){
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
};
void RandomPair(Pair& p) {
    int x = rand() % 1000;
    double y = (rand() % 1000) * 0.01;
    p = Pair(x, y);
}
ostream& operator <<(ostream& os, list<Pair>& list) {
    for_each(list.begin(), list.end(), [](Pair& p) {cout << p << endl; });
    return os;
}

int main() {
    system("chcp 1251>NULL");
    cout << "Введите размер списка: ";
    int N;
    cin >> N;
    Pair sum;
    list<Pair> list_1(N);
    generate(list_1.begin(), list_1.end(), []() {Pair p; RandomPair(p); return p; });
    cout << "Созданный список: " << endl << list_1 << endl << endl;
    for_each(list_1.begin(), list_1.end(), [&sum](Pair& p) {sum = sum + p; });
    sum.setX(sum.returnX() / list_1.size());
    sum.setY(((sum.returnY() * 10000) / list_1.size()) * 0.0001);
    cout << "Среднее арифмитическое: " << endl << sum << endl << endl;
    list_1.push_back(sum);
    cout << "Список, с добавленным в конец средним арифмитическим: " << endl << list_1 << endl << endl;
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
    list<Pair>::iterator s = remove_if(list_1.begin(), list_1.end(), [one, two](Pair& p) {return p > one && p < two; });
    list_1.erase(s, list_1.end());
    cout << "Полученный список: " << endl << list_1 << endl << endl;
    pair<list<Pair>::iterator, list<Pair>::iterator> stl_pair = minmax_element(list_1.begin(), list_1.end());
    cout << "Минимальный элемент: " << *stl_pair.first << endl;
    cout << "Максимальный элемент: " << *stl_pair.second << endl;
    Pair sum_pair(stl_pair.first->returnX() + stl_pair.second->returnX(), stl_pair.first->returnY() + stl_pair.second->returnY());
    cout << "Сумма max и min: " << endl << sum_pair << endl;
    for_each(list_1.begin(), list_1.end(), [&sum_pair](Pair& p) {p = p + sum_pair; });
    cout << "Полученный список, каждый элемент которого увеличен на сумму max+min: " << endl << list_1 << endl << endl;
    list_1.sort([](Pair& a, Pair& b) {return a < b; });
    cout << "Список, отсортированный по возрастанию: " << endl << list_1 << endl << endl;
    list_1.sort([](Pair& a, Pair& b) {return a > b; });
    cout << "Список, отсортированный по убыванию: " << endl << list_1 << endl << endl;
    cout << "Введите значение (целочисленное), по которому надо найти элемент в списке: " << endl;
    int x;
    cin >> x;
    auto i = find_if(list_1.begin(), list_1.end(), [&x](Pair& p) {return x == p.returnX(); });
    if (i != end(list_1)) {
        cout << "Элемент найден: " << *i << endl;
    }
    else {
        cout << "Элемент не найден";
    }
    return 0;
}
