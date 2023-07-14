#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(int val, Node* &head){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void printLL(Node* head){

    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* MiddleNode(Node* head){
    // constraint is there must be atleast one node in the given LL.
    if(!head->next){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node* head = new Node(10);
    insertAtHead(20, head);
    insertAtHead(30, head);
    insertAtHead(40, head);
    insertAtHead(50, head);
    // insertAtHead(60, head);

    printLL(head);
    Node* Mid = MiddleNode(head);
    cout<<Mid->val<<endl;
    return 0;
}