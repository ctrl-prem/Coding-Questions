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

void print(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}

ListNode* nodeToSwap(ListNode* head){
    ListNode* prev = NULL;
    ListNode* temp = head;
    while(head->next){
        if(head->next->val<temp->val){
            prev = head;
            temp = head->next;
        }
        head = head->next;
    }
    return prev;
}

ListNode* swaping(ListNode* prev, ListNode* prev1, ListNode* head, ListNode* curr){
    ListNode* temp = head->next;
    if(!prev){
        head->next = curr->next;
        prev1->next = head;
        curr->next = temp;
        return curr;
    }

    prev->next = curr;
    prev1->next = head;
    head->next = curr->next;
    curr->next = temp;
    return curr;
}

ListNode* selectionSort(ListNode* prev, ListNode* head){
    if(!head or !head->next){
        return head;
    }

    ListNode* curr = nodeToSwap(head);
    
    if(curr and curr->next){
        ListNode* prev1 = curr;
        curr = curr->next;
        head = swaping(prev, prev1, head, curr);
        ListNode* nodeReturned = selectionSort(head, head->next);
        head->next = nodeReturned;
    }
    return head;
}

int main(){
    ListNode* head = new ListNode(30);
    head->next = new ListNode(50);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(40);

    print(head);
    cout<<endl;
    ListNode* prev = NULL;
    head = selectionSort(prev, head);

    print(head);
    cout<<endl;
}