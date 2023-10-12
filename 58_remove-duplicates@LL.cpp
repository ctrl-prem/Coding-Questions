// remove duplicates from a sorted Linked List.
#include<iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int val){
            this->val = val;
            this->next = NULL;
        }
};

void insertAthead(ListNode* &head, int val){
    ListNode* temp = new ListNode(val);
    temp->next = head;
    head = temp;
}

void printLL(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}

void removeDuplicate(ListNode* head){
    if(!head or !head->next){
        // return head;
        return;
    }
    ListNode* prev = head;
    ListNode* curr = head->next;

    while(curr){
        if(curr->val != prev->val){
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    prev->next = NULL;

    // return head;
}

int main(){
    ListNode* head1 = NULL;
    insertAthead(head1, 3);
    insertAthead(head1, 3);
    insertAthead(head1, 3);
    insertAthead(head1, 3);
    insertAthead(head1, 2);
    insertAthead(head1, 2);
    insertAthead(head1, 1);
    insertAthead(head1, 1);

    // ListNode* head = removeDuplicate(head1);
    removeDuplicate(head1);
    printLL(head1);
    return 0;
}