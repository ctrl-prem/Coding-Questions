// remove all the similar nodes(with same value) if duplicate exist.
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

// Recursive Approach.
ListNode* removeDuplicates(ListNode* head){
    if(!head or !head->next){
        return head;
    }

    ListNode* curr = head;
    if(curr->val != curr->next->val){
        ListNode* temp = removeDuplicates(curr->next);
        head->next = temp;
        return head;
    }
    else{
        while(curr->next and curr->val == curr->next->val){
            curr = curr->next;
        }
        return removeDuplicates(curr->next);
    }

}

// Iterative Approach
ListNode* removeDuplicatesIt(ListNode* head){
    if(!head or !head->next){
        return head;
    }

    ListNode* curr = head;
    ListNode* temp = NULL;
    ListNode* newhead = NULL;
    bool flag = true;

    while(curr and curr->next){
        if(curr->val != curr->next->val){
            if(flag){
                temp = curr;
                newhead = temp;
                flag = false;
            }
            else{
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
        }
        else{
            while(curr->next and curr->val == curr->next->val){
                curr = curr->next;
            }
            curr = curr->next;
        }
    }

    if(temp){
        temp->next = curr;
    }
    else{
        if(curr){
            newhead = curr;
        }
    }

    return newhead;
}

int main(){
    ListNode* head = NULL;
    insertAthead(head, 4);
    insertAthead(head, 4);
    insertAthead(head, 3);
    insertAthead(head, 2);
    insertAthead(head, 1);
    insertAthead(head, 1);

    // ListNode* newhead = removeDuplicates(head);
    // printLL(newhead);

    ListNode* itHead = removeDuplicatesIt(head);
    printLL(itHead);
    return 0;
}