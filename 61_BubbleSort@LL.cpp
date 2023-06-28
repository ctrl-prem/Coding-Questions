#include<iostream>
using namespace std;

class node {
    public:
    int val;
    node* next;

    node(int val){
        this->val = val;
        this->next = NULL;
    }

    void insertAtHead(int val, node* &head){
        node* temp = new node(val);
        temp->next = head;
        head = temp;
    }

    void print(node* head){
        node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    node* head = new node(50);
    head->insertAtHead(40, head);
    head->insertAtHead(30, head);
    head->insertAtHead(20, head);
    head->insertAtHead(10, head);
    head->print(head);
    return 0;
}