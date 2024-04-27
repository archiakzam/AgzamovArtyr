#include <iostream>
#include <algorithm>
#include <random>
#include <queue>
#include <functional>
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
        cout << "� " << this->x << " ��������� const " << j << ": " << endl;
        this->x = x + j;
    }
    void dobavlenieConst(double i) {
        cout << "� " << this->y << " ��������� const " << i << ": " << endl;
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
        cout << "� " << this->x << " ��������� const " << j << ": " << endl;
        this->x = x + j;
    }
    void operator +(double k) {
        cout << "� " << this->y << " ��������� const " << k << ": " << endl;
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
        cout << "������� ������ (�����) �����: ";
        is >> p.x;
        cout << "������� ������ (������������) �����: ";
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

class Greater_ThanPair {
public:
    bool operator () (Pair& p1, Pair& p2) {
        return p1 < p2;
    }
};
void genetare_Q(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q, int& size) {
    Pair qwe(0, 0);
    for (int i = 0; i < size; i++) {
        RandomPair(qwe);
        q.push(qwe);
    }
}
ostream& operator<<(ostream& os, const priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q) {
    auto temp_q = q;
    while (!temp_q.empty()) {
        Pair user = temp_q.top();
        os << user << endl;
        temp_q.pop();
    }
    return os;
}

Pair all_sum(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q) {
    Pair p(0, 0);
    auto temp_q = q;
    while (!temp_q.empty()) {
        Pair user = temp_q.top();
        p = p + user;
        temp_q.pop();
    }
    return p;
}
void remove_from_range(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q, Pair& range1, Pair& range2) {
    priority_queue<Pair, vector<Pair>, Greater_ThanPair> q1;
    auto temp_q = q;
    while (!temp_q.empty()) {
        Pair user = temp_q.top();
        if (!(user > range1 && user < range2)) {
            q1.push(user);
        }
        temp_q.pop();
    }
    q = q1;
}
Pair max(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q) {
    Pair max_p = q.top();
    return max_p;
}
Pair min(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q) {
    auto temp_q = q; 
    Pair min_p;
    while (!temp_q.empty()) {
        min_p = temp_q.top();
        temp_q.pop();
    }
    return min_p;
}


priority_queue<Pair, vector<Pair>, Greater_ThanPair> add(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q, Pair& para) {
    priority_queue<Pair, vector<Pair>, Greater_ThanPair> q1;
    auto temp_q = q;
    while (!temp_q.empty()) {
        Pair temp = temp_q.top();
        q1.push(temp + para);
        temp_q.pop();
    }
    return q1;
}

bool find_para(priority_queue<Pair, vector<Pair>, Greater_ThanPair>& q, int& x, Pair& p) {
    auto temp_q = q;
    while (!temp_q.empty()) {
        p = temp_q.top();
        if (x == p.returnX()) {
            return true;
        }
        temp_q.pop();
    }
    return false;
}

int main() {
    system("chcp 1251>NULL");
    cout << "������� ������ �������: ";
    int N;
    cin >> N;
    priority_queue<Pair, vector<Pair>, Greater_ThanPair> q;
    int x = 0;
    double y = 0;
    Pair p(x, y);
    for (int i = 0; i < N; i++) {
        cin >> p;
        q.push(p);
    }
    cout << q;
    p = all_sum(q);
    p.setX(p.returnX() / N);
    p.setY(((p.returnY() * 1000) / N) * 0.001);
    cout << endl;
    cout << "������� ��������������: " << endl << p << endl << endl;
    q.push(p);
    cout << "����� ���������� �������� ���������������: " << endl << q << endl << endl;
    Pair one, two;
    cout << "������� ���� �����, �������� ������� ����� ������� ��������� �����: " << endl;
    cout << "������ ����: " << endl;
    cin >> one;
    cout << "������ ����: " << endl;
    cin >> two;
    if (one > two) {
        swap(one, two);
    }
    remove_from_range(q, one, two);
    cout << "����� ��������: " << endl << q << endl << endl;
    Pair maxel = max(q);
    Pair minel = min(q);
    cout << "������������ �������: " << endl << maxel << endl;
    cout << "����������� �������: " << endl << minel << endl << endl;
    p = maxel + minel;
    cout << "����� max � min: " << endl << p << endl << endl;
    q.push(p);
    cout << "������� ����� ���������� max � min: " << endl << q << endl << endl;
    cout << "������� ������������� X, ������� ����� �����: " << endl;
    Pair sum(0, 0);
    int X;
    cin >> X;
    bool flag = find_para(q, X, p);
    if (flag) {
        cout << "������� ������: " << p;
    }
    else {
        cout << "������� �� ������";
    }
    return 0;
}
