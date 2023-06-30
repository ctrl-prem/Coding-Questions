// Implementation of Stack using Singly Linked List.
#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class stack {
public:
    Node<T>* head;
    int count;

    stack(){
        head = NULL;
        count = 0;
    }

    void push(T data){
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head = temp;
        count++;
    }
    void pop(){
        if(head){ 
            head = head->next;
            count--;
        }
    }
    T top(){
        return head->data;
    }
    int size(){
        return count;
    }
    bool empty(){
        return head ? 1 : 0;
    }
    void printAllelements(){
        Node<T>* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    stack<int> s;
    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.printAllelements();
    cout<<endl;
    return 0;
}