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

ListNode* merge(ListNode* head1, ListNode* head2){
    // base case
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }

    // recursive case
    ListNode* head = NULL;
    if(head1->val >= head2->val){
        head = head2;
        ListNode* temp = merge(head1, head2->next);
        head->next = temp;
    }
    else{
        head = head1;
        ListNode* temp = merge(head1->next, head2);
        head->next = temp;
    }

    return head;
}

ListNode* iterativeMerge(ListNode* head1, ListNode* head2){
    if(!head1) return head2;
    if(!head2) return head1;

    // ListNode* head = NULL;
    // if(head1->val >= head2->val){
    //     head = head2;
    //     head2 = head2->next;
    //     head->next = NULL;
    // }
    // else{
    //     head = head1;
    //     head1 = head1->next;
    //     head->next = NULL;
    // }

    ListNode* head = new ListNode(0); // Concept of dummy node. solving using dummy node.
    ListNode* temp = head;

    while(head1 and head2){
        if(head1->val >= head2->val){
            temp->next = head2;
            head2 = head2->next;
            if(temp->next){
                temp = temp->next;
            }
        }
        else{
            temp->next = head1;
            head1 = head1->next;
            if(temp->next){
                temp = temp->next;
            }
        }
    }

    if(head1){
        temp->next = head1;
    }
    if(head2){
        temp->next = head2;
    }

    return head->next;
}

int main(){
    ListNode* head1 = new ListNode(10);
    head1->next = new ListNode(30);
    head1->next->next = new ListNode(50);

    ListNode* head2 = new ListNode(20);
    head2->next = new ListNode(40);
    head2->next->next = new ListNode(60);

    // ListNode* head = merge(head1, head2);
    // printNodes(head);

    ListNode* headi = iterativeMerge(head1, head2);
    printNodes(headi);
    return 0;
}