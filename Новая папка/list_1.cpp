#include <iostream>
#include <windows.h>
using namespace std;
struct Node
{
    char data;
    Node* next = nullptr;
};

struct List
{
    int size = 0;
    Node* head = nullptr;
};

void add(List*& list, char data)
{
    Node* new_node = new Node;
    new_node->data = data;
    if (list->head == nullptr)
    {
        list->head = new_node;
    }
    else
    {
        Node* current_node = list->head;
        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    list->size++;
}

void out(List*& list)
{
    Node* current_node = list->head;
    while (current_node != nullptr && list->size != 0)
    {
        cout << current_node->data << ' ';
        current_node = current_node->next;
    }
    cout << endl;
}

void put(List*& list, int index, char data)
{
    Node* new_node = new Node;
    new_node->data = data;

    if (index == 0)
    {
        new_node->next = list->head;
        list->head = new_node;
    }

    Node* current_node = list->head;
    for (int i = 0; i < index - 1; i++)
    {
        current_node = current_node->next;
    }
    Node* next_node = current_node->next;
    current_node->next = new_node;
    new_node->next = next_node;
}

void push(List*& list, char key)
{
    Node* current_node = list->head;
    if (list->head->data == key)
    {
        list->head = list->head->next;
        return;
    }
    while (current_node->next != nullptr && current_node->next->data != key)
    {
        current_node = current_node->next;
    }
    current_node->next = current_node->next->next;

}

void del_list(List*& list)
{
    Node* current_node = list->head;
    while (current_node != nullptr)
    {
        Node* next_node = current_node->next;
        delete current_node;
        list->size--;
        current_node = next_node;
    }
    delete current_node;
    delete list;
}

void extra_put(List*& list, int number, int count, char symb)
{
    Node* current_node = list->head;
    for (int i = 0; i < number - 1; i++)
    {
        current_node = current_node->next;
    }
    for (int i = number-1; i < count + number - 1; i++)
    {
        put(list, i, symb);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");
    char key, symb;
    int number, count;
    char arr[] {'0', '1', '2', '3', '4', '5', '6'};
    List* list = new List;

    for (int i = 0; i < sizeof(arr); i++)
    {
        add(list, arr[i]);
    }
    
    out(list);
    cout << "Введите ключ который необходимо удалить:";
    cin >> key;
    push(list, key);
    out(list);

    cout << "Введите количество элементов: ";
    cin >> count;
    cout << "Введите символ который нужно поставить: ";
    cin >> symb;
    extra_put(list, 1, count, symb);
    out(list);
    del_list(list);
}
