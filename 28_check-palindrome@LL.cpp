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

ListNode* midPt(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* reverse(ListNode* newHead){
    ListNode* prev = NULL;
    ListNode* curr = newHead;

    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

bool palindrome(ListNode* head){
    ListNode* midPoint = midPt(head);
    ListNode* newHead = midPoint->next;
    midPoint->next = NULL;
    newHead = reverse(newHead);

    while(newHead){
        if(head->val != newHead->val){
            return false;
        }

        head = head->next;
        newHead = newHead->next;
    }

    return true;
}

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(20);
    head->next->next->next->next->next = new ListNode(10);

    cout<<palindrome(head)<<endl;
    return 0;
}