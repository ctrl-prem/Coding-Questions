// Using cyclic as well as normal method.
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

void printNodes(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}

int lengthofLL(ListNode* head){

    int cnt = 0;
    while(head){
        cnt++;
        head=head->next;
    }

    return cnt;
}

ListNode* kRotation(ListNode* head, int k){

    if(!head){
        return head;
    }

    int n = lengthofLL(head);
    k = k%n;

    ListNode* fast = head;
    ListNode* tail = NULL;
    for(int i=0; i<k+1; i++){ //(k+1) coz we need sub-List of len. k
        if(!fast->next){
            tail = fast;
        }
        fast = fast->next;
    }

    ListNode* slow = head;
    while(fast){
        if(fast->next == NULL){
            tail = fast;
        }
        fast = fast->next;
        slow = slow->next;
    }

    if(!slow->next){
        return head;
    }

    ListNode* newHead = slow->next;
    slow->next = NULL;
    tail->next = head;

    return newHead;
}

ListNode* kRotation2(ListNode* head, int k){
    if(!head) return head;

    int n = 1;
    ListNode* tail = head;
    while(tail->next){
        n++;
        tail = tail->next;
    }
    k = k%n;
    if(k == 0){
        return head;
    }
    
    ListNode* newTail = head;
    for(int i=0; i<n-k-1; i++){
        newTail = newTail->next;
    }   

    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;

}

int main(){
    // ListNode* head = NULL;
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    int k;
    cin>>k;
    // head = kRotation(head, k);
    // printNodes(head);

    head = kRotation2(head, k);
    printNodes(head);
    return 0;
}