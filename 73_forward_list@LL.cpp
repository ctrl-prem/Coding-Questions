#include<iostream>
using namespace std;

template<typename T>
class Node {
    T data;
    Node<T>* next; //basically It's a pointer and to identify the type of pointer we define as, Node<T>* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

class forward_list{
    Node<T>* head;
    
};