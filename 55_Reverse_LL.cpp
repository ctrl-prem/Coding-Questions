#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insertAthead(ListNode* &head, int val){
    ListNode* temp=new ListNode(val);
    temp->next=head;
    head=temp;
}

void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

void reverseLL(ListNode* &head){
    ListNode* curr;
    ListNode* temp;
    while(head!=NULL){
        curr=head;
        temp=head->next;
        curr->next=NULL;
        temp->next=head;
        head=head->next;
    }
}

int main(){
    ListNode* head= new ListNode(5);
    // cout<<head->val<<endl;
    insertAthead(head, 2);
    insertAthead(head, 4);
    insertAthead(head, 6);
    insertAthead(head, 7);
    insertAthead(head, 3);
    insertAthead(head, 1);
    insertAthead(head, 8);
    print(head);
    cout<<endl; 
    reverseLL(head);
    print(head);
}