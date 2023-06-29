#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next; //basically It's a pointer and to identify the type of pointer we define as, Node<T>* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class forward_list{
public:
    Node<T>* head;
    forward_list(){
        this->head = NULL;
    }
    void push_front(T data){
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head = temp;
    }
    void pop_front(){
        if(head) head = head->next;
    }
    T front(){
        return head->data;
    }
    void traverse(){
        Node<T>* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    bool empty(){
        return head ? 0:1;
    }
    void clear(){
        head = NULL;
    }
};

int main(){
    forward_list<string> fl;
    fl.push_front("prem");
    fl.push_front("himanshu");
    fl.push_front("ram");
    fl.push_front("hocho-hocho");
    fl.push_front("family");
    fl.traverse();
    cout<<endl;
    cout<<fl.front()<<endl;
    fl.pop_front();
    fl.traverse();
    cout<<endl;
    fl.clear();
    cout<<fl.empty()<<endl;
    return 0;
}