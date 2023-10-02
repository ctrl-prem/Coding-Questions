// Apply recursive as well iterative approach for the solution.
// Corner cases for the problem.
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

// Iterative approach
Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// Recursive approach
void RecReverse(Node* &head, Node* temp, Node* prev){
    // base case
    if(!temp){
        head = prev;
        return;
    }
    // recursive case
    Node* curr = temp->next;
    RecReverse(head, curr, temp);
    curr->next = prev;
}

int main(){
    Node* head = new Node(10);
    insertAtHead(20, head);
    insertAtHead(30, head);
    insertAtHead(40, head);
    insertAtHead(50, head);
    insertAtHead(60, head);

    printLL(head);
    head = reverseLL(head);
    printLL(head);
    Node* prev = NULL;
    Node* temp = head;
    RecReverse(head, temp, prev);
    printLL(head);

    return 0;
}