
#include <iostream>
#include <string>
#include <ctime>
#include<cmath>
#include <list>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

template<typename T>
class Tree {
private:
	Tree<T>* left;
	Tree<T>* right;
	Tree<T>* parent;
	T data;
public:
	Tree<T>() {//����������������������
		left = right = parent = nullptr;
	}
	Tree<T>(T data) {//����������� �� ��������� 
		this->data = data;
		left = right = parent = nullptr;
	}
	~Tree<T>() {//����������
		delete_right();
		delete_left();
		delete_tree();
	}
	void insert(T data) {//��������� ����� ���� �� ��������� data � ������ ����� � ������
		Tree<T>* current = this;
		while (current != nullptr) {
			if (data > current->data) {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current->insert_right(data);
					return;
				}
			}
			else if (data < current->data) {
				if (current->left != nullptr) {
					current = current->left;
				}
				else {
					current->insert_left(data);
					return;
				}
			}
			else return;
		}
	}
	void insert_right(T data) {//��������� ����� ���� �� ��������� data � ������ ���������
		Tree<T>* new_node = new Tree(data);
		if (this->right != nullptr) {
			this->right->parent = new_node;
			new_node->right = this->right;
		}
		this->right = new_node;
		new_node->parent = this;
	}
	void insert_left(T data) {//��������� ����� ���� �� ��������� data � ����� ���������
		left = new Tree<T>(data);
		left->parent = this;
	}
	void delete_tree(){//������� ��������� ������
		delete this;
	}
	T get_data() {//���������� �������� � data
		return this->data;
	}
	Tree<T>* get_right() {//���������� ��������� �� ������ ���������
		return this->right;
	}
	Tree<T>* get_left() {//���������� ��������� �� ����� ���������
		return this->left;
	}
	Tree<T>* get_parent() {//���������� ��������� �� ������������ ����
		return this->parent;
	}
	void erase(T data) {//�������, ������� ������� ���� � �������� ���������
		Tree<T>* to_erase = this->find(data);
		Tree<T>* to_parent = to_erase->parent;
		if (to_erase->left == nullptr&&to_erase->right == nullptr) {
			if (to_parent->left == nullptr) {
				to_parent->left == nullptr;
				delete to_erase;
			}
			else {
				to_parent->right == nullptr;
				delete to_erase;
			}
		}
		else if ((to_erase->left != nullptr&&to_erase->right != nullptr) || ((to_erase->left == nullptr&&to_erase->right != nullptr))) {
			if (to_erase->left==nullptr) {
				if (to_erase == to_parent->left) {
					to_parent->left = to_erase->right;
				}
				else {
					to_parent->righjt == to_erase->right;
				}
				to_erase->right->parent = to_parent;
			}
			else {
				if (to_parent->left == to_erase) {
					to_parent->left = to_erase->left;
				}
				else {
					to_parent->right = to_erase->left;
				}
				to_erase->left->parent = to_parent;
			}
		}
		else {
			Tree<T>* next = to_erase->next();
			to_erase->data = next->data;
			if (next == next->parent->left) {
				next->parent->left = next->right;
				if (next->right != nullptr) {
					next->right->parent = next->parent;
				}
			}
			else {
				next->parent->right = next->right;
				if (next->right != nullptr) {
					next->right->parent = next->parent;
				}
			}
			delete next;
		}
	}
	void delete_left() {//������� ����� ���������
		if (left != NULL) {
			left->delete_left();
			left->delete_right();
			delete left;
		}
	}
	void delete_right() {//������� ������ ���������
		if (right != NULL) {
			right->delete_right;
			right->delete_left();
			delete right;
		}
	}
	void add_right(Tree<T>* temp) {//�������, ������� ������������� ������ ���������
		right = temp;
	}
	void add_left (Tree<T>*temp){//�������, ������� ������������� ����� ���������
		left = temp;
	}
	Tree<T>search(T key) {//���� ���� �� ��������� �����
		if (data == key) {
			return this;
		}
		if (left != nullptr) {
			Tree<T>* result = left->search(key);
			if (result != nullptr) {
				return result;
			}
		}
		if (right != nullptr) {
			Tree<T>* result = right->search(key);
			if (result != nullptr) {
				return result;
			}
		}
		return nullptr;
	}
	Tree<T>find(T data) {//�������, ������� ���� ���� � �������� ���������
		if (this == nullptr || this->data == data) {
			return this;
		}
		else if (data > this->data) {
			return this->right->find(data);
		}
		else {
			return this->left->find(data);
		}
	}
	
	void direct_way(Tree<T>* current) {//�����������������
		if (current == nullptr) {
			return;
		}
		else {
			cout<< current->get_data() << " ";
			direct_way(current->get_left());
			direct_way(current->get_right());
		}
	}


	void symmetric_way(Tree<T>* tree) {//�����������������������
		if (tree !=nullptr) {
			symmetric_way(tree->left);
			cout<< tree->data << " ";
			symmetric_way(tree->right);
		}
	}

	void reverse_way(Tree<T>* tree) {//�������������������
		if (tree != nullptr) {
			reverse_way(tree->left);
			reverse_way(tree->right);
			cout<< tree->data << " ";
		}
	}
	Tree<T>* balanced(int count) {//�������, ������� ������ ���������������� ������ � ������ �������
		if (count <= 0) {
			return nullptr;
		}
		T data;
		cout<< "������� ������ ��� ����������������� ������: ";
		cin>> data;
		Tree<T>* temp = new Tree<T>(data);
		temp->add_left(balanced(count / 2));
		temp->add_right(balanced(count - count / 2 - 1));
		return temp;
	}
	int getHeight() {//�������, ������� ���������� ������ ������ 
		int h1 = 0, h2 = 0, hadd = 0;
		if (this == NULL) {
			return 0;
		}
		if (this->left != NULL) {
			h1 = this->left->getHeight();
		}
		if (this->right != NULL) {
			h2 = this->right->getHeight();
		}
		if (h1 >= h2) {
			return h1 + 1;
		}
		else return h2 + 1;
	}
	int getAmountOfNodes() {//�������, ������� ���������� ���-�� ����� � ������
		if (this == NULL) {
			return 0;
		}
		if ((this->left == NULL) && (this->right == NULL)) {
			return 1;
		}
		int l = 0;
		int r = 0;
		if (this->left != NULL) {
			l = this->left->getAmountOfNodes();
		}
		if (this->right != NULL) {
			r = this->right->getAmountOfNodes();
		}
		return (l + r + 1);
	}
	void obh(Tree<T>* node) { //�������������� ������� ��� ������������ ������ ������
		ofstream f("print.txt");
		int amount = node->getAmountOfNodes();
		queue<Tree<T>*>q;
		q.push(node);
		while (!q.empty()) {
			Tree<T>* temp = q.front();
			q.pop();
			f << temp->data <<endl;
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
		f.close();
	}
	void printVert() { //������������ ������ ������
		obh(this);
		ifstream f("print.txt");
		int height = this->getHeight();
		int count = 0;
		int* spaces = new int[height];
		spaces[0] = 0;
		for (int i = 1; i< height; i++) {
			spaces[i] = spaces[i - 1] * 2 + 1;
		}

		char str[255];
		for (int i = 0, l = height - 1; i< height; i++, l--) {
			for (int j = 0; j < pow(2,i); j++) {
				if (j == 0) {
					for (int u = 0; u < spaces[l]; u++) {
						cout<< " ";
					}
				}
				else {
					for (int u = 0; u < spaces[l + 1]; u++) {
						cout<< " ";
					}
				}
				if (f.getline(str, 255)) {
					cout<<str;
				}
				else {
					cout<< " ";
				}
			}
			cout<<endl;
		}
		delete[] spaces;
		f.close();
	}


	void print_horizontal (int depht = 0, char branch = ' ') { //��������������������������
		if (right != nullptr) {
			right->print_horizontal(depht + 1, '/');
		}
		for (int i = 0; i<depht; i++) {
			cout<< "   ";
		}
		cout<< branch << "--" << data <<endl;
		if (left != nullptr) {
			left->print_horizontal(depht + 1, '\\');
		}
	}
	static Tree<T>* build_bst(const vector<T> data , int start, int end) {//�����������������������������������������������������
		if (start > end) {
			return nullptr;
		}
		int mid = start + (end - start) / 2;
		Tree<T>* new_node = new Tree<T>(data[mid]);
		new_node->left = build_bst(data, start, mid - 1);
		new_node->right = build_bst(data, mid + 1, end);
		return new_node;
	}
	void in_order_traversal(vector<T>&result) {//����� ������ � ������� ����������� � ���������� �������� � �������
		if (left != nullptr) {
			left->in_order_traversal(result);
		}
		result.push_back(data);
		if (right != nullptr) {
			right->in_order_traversal(result);
		}
	}
	static Tree<T>* create_bst(Tree<T>* root) {//������ ��� �������� ������ ������ �� ����������������� ������ 
		vector<T>sorted_data;
		root->in_order_traversal(sorted_data);
		return build_bst(sorted_data, 0, sorted_data.size() - 1);
	}
    

};

int main() {
	system("chcp 1251>NULL");
	Tree<char>* root = new Tree<char>('a');
	root->insert_left('b');
	root->insert_right('c');
	root->get_left()->insert_left('d');
	root->get_left()->insert_right('e');
	root->get_right()->insert_left('f');
	root->get_right()->insert_right('g');
	cout<< "�������������� ����� ������: " <<endl;
	root->print_horizontal();
	cout<<endl<<endl;
	cout<< "������������ ����� ������: " <<endl;
	root->printVert();
	cout<<endl<<endl;
	cout<< "�����������: " <<endl;
	root->direct_way(root);
	cout<<endl;
	cout<< "�����������������: " <<endl;
	root->symmetric_way(root);
	cout<<endl;
	cout<< "�������������: " <<endl;
	root->reverse_way(root);
	cout<<endl<<endl;
	Tree<char>* bal = new Tree<char>('a');
	int count;
	cout<< "������� ���-�� ��������� � ���������������� ������: ";
	cin>> count;
	Tree<char>* bal1 = bal->balanced(count);
	cout<<endl;
	cout<< "�������������� ����� ����������������� ������: " <<endl;
	bal1->print_horizontal();
	cout<<endl<<endl;
	cout<< "������������ ����� ����������������� ������: " <<endl;
	bal1->printVert();
	cout<<endl<<endl;
	cout<< "����������� ������, � ������ ������: " <<endl;
	bal1->create_bst(bal1);
	cout<< "�������������� ����� ������ ������: " <<endl;
	bal1->print_horizontal();
	cout<<endl<<endl;

	char s;

	int l = 0;
	queue<Tree<char>*>q;
	q.push(bal1);
	while (!q.empty()) {
		Tree<char>* current = q.front();
		q.pop();
		if (current->get_data() > s) {
			s=current->get_data();
		}
		if (current->get_left() != nullptr) {
			q.push(current->get_left());
		}
		if (current->get_right() != nullptr) {
			q.push(current->get_right());
		}
	}
	cout<< "Max element " << s<<endl;
	return 0;

}
