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

void insertAtHead(ListNode* &head, int val){
    ListNode* temp=new ListNode(val);
    temp->next=head;
    head=temp;
    return;
}

void printLinkedList(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    return;
}

void deleteFromHead(ListNode* &head){
    if(head==NULL){
        return;
    }

    ListNode* temp = head->next;
    delete head;
    head=temp;
    return;
}

int main(){
    ListNode* head=NULL;
    // ListNode* head=new ListNode(10);
    // insertAtHead(head, 40);
    // cout<<head->val<<endl;
    // cout<<"before deleting the node "<<endl;
    // printLinkedList(head);
    // cout<<endl;
    // cout<<"After deleting the node "<<endl;
    deleteFromHead(head);
    // printLinkedList(head);
    // cout<<endl;
    return 0;
}