#include <iostream>
#include <windows.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};
struct Stack {
    Node* head = nullptr;
    int size = 0;
};

void push(Stack& q, char a)
{
    Node* new_node = new Node;
    new_node->data = a;
    new_node->next = q.head;
    q.head = new_node;
    q.size++;
}

void pop(Stack& q) {
    Node* delete_node = q.head;
    q.head = delete_node->next;
    delete delete_node;
    q.size--;
}

char top(Stack& q) {
    return q.head->data;
}
void print(Stack& q1, Stack& q2)
{
    while(q1.size != 0)
    {
        push(q2, top(q1));
        cout<<top(q1)<<" ";
        pop(q1);
    }
    cout<<endl;
}

int main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL,"RU");
    int n;
    Stack q1, q2;
    cout << "Enter number of elements:";
    cin >> n;
    cout << "enter element:";
    for (int i = 0; n > i; i++) {
        char a;
        cin >> a;
        push(q1, a);
}
    cout << "stack: ";
    print(q1,q2);
    cout << "enter key: ";
    char key;
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (top(q2) == key) {
            pop(q2);
    }
        else {
            push(q1, top(q2));
            pop(q2);
    }
    }
    cout << "Stack after delete: ";
    print(q1, q2);
    cout << "Enter count elements: ";
    int k,s;
    cin >> k;
    s=1;
    n = q2.size;
    for (int i = 0; i < n - s+1; i++) {
        push(q1, top(q2));
        pop(q2);
   
    }
    cout << "Enter new elements: ";
    for (int i = 0; i < k; i++) {
        char a;
        cin >> a;
        push(q1, a);
    }
    while (q2.head != nullptr) {
        push(q1, top(q2));
        pop(q2);
    }
    cout << "Stack: ";
    print(q1, q2);

    }
