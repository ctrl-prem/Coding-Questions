// input is in reverse order. output should be in right order.
// Here, we are considering that the number already in reverse order. If Not then reverse first and apply the function below.

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

// ListNode* sumEqual(ListNode* head1, ListNode* head2){
//     ListNode* head = NULL;
//     int carry = 0;
//     while(head1 and head2){
//         int d1 = head1 ? head1->val : 0;
//         int d2 = head2 ? head2->val : 0;

//         int sum = d1 + d2 + carry;
//         insertAthead(head, sum%10);
//         carry = sum/10;

//         head1 = head1->next ? head1->next : NULL;
//         head2 = head2->next ? head2->next : NULL;
//     }

//     if(carry){
//         insertAthead(head, carry);
//     }

//     return head;
// }

ListNode* sumUnequal(ListNode* head1, ListNode* head2){
    ListNode* head = NULL;
    int carry = 0;
    while(head1 or head2 or carry){
        int d1 = head1 ? head1->val : 0;
        int d2 = head2 ? head2->val : 0;

        int sum = d1 + d2 + carry;
        insertAthead(head, sum%10);
        carry = sum/10;

        head1 = head1 ? head1->next : NULL;
        head2 = head2 ? head2->next : NULL;
    }

    return head;
}

int main(){
    ListNode* head = NULL;
    insertAthead(head, 9);
    insertAthead(head, 9);
    insertAthead(head, 9);
    insertAthead(head, 4);
    insertAthead(head, 2);
    insertAthead(head, 1);

    ListNode* head1 = NULL;
    insertAthead(head1, 6);
    insertAthead(head1, 5);
    insertAthead(head1, 9);

    // ListNode* sum = sumEqual(head, head1);
    // printLL(sum);

    ListNode* sum1 = sumUnequal(head, head1);
    printLL(sum1);
    return 0;
}