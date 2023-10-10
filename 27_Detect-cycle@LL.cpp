// detect node at which cycle is starting and print the value.

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

bool isCyclePresent(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}

ListNode* detectCyclicNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(!fast or !fast->next){
        return NULL;
    }

    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void breakThecycle(ListNode* head){
    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(!fast or !fast->next){
        return;
    }

    slow = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return;
}

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = head->next->next;

    isCyclePresent(head) ? cout<<"Yes Present"<<endl : cout<<"Not Present"<<endl;

    ListNode* cyclicNode = detectCyclicNode(head);
    cyclicNode ? cout<<cyclicNode->val<<endl : cout<<"NAN"<<endl;

    breakThecycle(head);
    printNodes(head);
    return 0;
}