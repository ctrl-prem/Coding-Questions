// Reverse nodes in set of k-nodes of a Linked List.

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

void printNode(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}

ListNode* revNodes(ListNode* head, int k){
    // base case
    if(!head){
        return NULL;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    int j=0;
    
    while(curr and j<k){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        j++;
    }
    // recursive case

    ListNode* revHead = revNodes(curr, k);
    head->next = revHead;

    return prev;

}

ListNode* revNodes1(ListNode* head, int k, int cnt){
    // base case
    if(!head or cnt<k){
        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    int j=0;
    
    while(curr and j<k){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        j++;
    }
    // recursive case

    ListNode* revHead = revNodes1(curr, k, cnt-k);
    head->next = revHead;

    return prev;

}

int main(){
    
    ListNode* head = NULL;
    head = new ListNode(10);
    head->next = new ListNode(50);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(20);

    printNode(head);
    cout<<endl;

    int k;
    cin>>k;

    // k nodes should be reversed if there is less nodes, then reverse all rest nodes.
    head = revNodes(head, k);

    printNode(head);
    cout<<endl;

    // k nodes should be reversed if there is less than k nodes, then, do not reverse the rest nodes.
    int cnt = 0;
    ListNode* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }

    head = revNodes1(head, k, cnt);

    printNode(head);
    cout<<endl;

    return 0;
}