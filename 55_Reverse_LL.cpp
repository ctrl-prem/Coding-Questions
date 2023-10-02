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

// Iterative approach
void reverseLL(ListNode* &head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

// Recursive approach
ListNode* recReverse(ListNode* head){
    if(!head or !head->next){
        return head;
    }
//          OR
    // if(!head){
    //     return NULL;
    // }
    // if(!head->next){
    //     return head;
    // }
    
    ListNode* getNode = recReverse(head->next);
    ListNode* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return getNode;
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

    head = recReverse(head);
    cout<<endl;
    print(head);
    cout<<endl;
}