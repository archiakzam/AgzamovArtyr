#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    char *key=new char[1];
    Node *prev_node_ptr=nullptr;
    Node *next_node_ptr=nullptr;

};

struct List{
    Node*head_node=nullptr;
    Node* tail_node=nullptr;
    int size=0;
};
 void delete_key(List& list,char key){
    if(list.head_node==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* remove_node=list.head_node;
    while((*(remove_node->key)!=key)&&(remove_node!=nullptr)){
        remove_node=remove_node->next_node_ptr;
    }
    if(remove_node==nullptr){
        cout<<"No key found"<<endl;
        return;
    }
    if((list.head_node==remove_node)&&(list.tail_node==remove_node)){
        list.head_node==nullptr;
        list.tail_node==nullptr;
    }
    else if(list.head_node==remove_node){
        list.head_node==remove_node->next_node_ptr;
        remove_node->next_node_ptr->prev_node_ptr=nullptr;
    
    }
    else if(list.tail_node==remove_node){
        list.tail_node==remove_node->prev_node_ptr;
        remove_node->prev_node_ptr->next_node_ptr=nullptr;
    
    }
    else{
        remove_node->next_node_ptr->prev_node_ptr=remove_node->prev_node_ptr;
        remove_node->prev_node_ptr->next_node_ptr=remove_node->next_node_ptr;

    }
    delete remove_node;
 }
 void add_node(List& list,int index,char str){
    Node *new_node=new Node;
    *(new_node->key)=str;
    list.size++;
    if(list.head_node==nullptr){
        list.head_node=new_node;
        list.tail_node=new_node;
        return;
    }
    if((index==-1)or(index==0)){
        new_node->next_node_ptr=list.head_node;
        list.head_node->prev_node_ptr=new_node;
        list.head_node=new_node;
        return;
    }
    int counter=0;
    int from_tail=list.size-2-index;
    Node*current_node;
    if(index<from_tail){
        current_node=list.head_node;
        while(counter!=index){
            current_node=current_node->prev_node_ptr;
            ++counter;
        }
    }
    else{
        current_node=list.tail_node;
        while(counter!=from_tail){
            current_node=current_node->prev_node_ptr;
            ++counter;
        }
    }
    new_node->next_node_ptr=current_node;
    new_node->prev_node_ptr=current_node->prev_node_ptr;
    current_node->prev_node_ptr->next_node_ptr=new_node;
    current_node->prev_node_ptr=new_node;
 }
 void print_list(List&list){
    Node * current_node=list.head_node;
    if(current_node==nullptr){
        cout<<"List_is empty"<<endl;
        return;
    }
    cout<<"[";
    while(current_node!=nullptr){
        cout<<*(current_node->key)<<" ";
        current_node=current_node->next_node_ptr;
    }
    cout<<"\b \b\b \b]"<<endl;
    delete current_node;
 }
 int main(){
    int n,k;
    string str;
    char ch;
    List list;
    cout<<"Ender number of element: ";
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;++i){
        cout<<"Enter key for element: ";
        getline(cin,str);
        ch=str[0];
        add_node(list,0,ch);
    }
    print_list(list);
    cout<<"Enter key for deletion: ";
    getline(cin,str);
    ch=str[0];
    delete_key(list,ch);
    print_list(list);
    cout<<"Enter count element: ";
    cin>>k;
    cin.ignore();
    int l=0;
    for(int i=1;i<=k;++i){
        cout<<"Enter key for element: ";
        getline(cin,str);
        ch=str[0];
        add_node(list,0,ch);
    }
    print_list(list);
    return 0;
 }