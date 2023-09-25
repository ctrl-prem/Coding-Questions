// Do with the recursion and iterative approach as well.
// Calculate the length of the linked list.
// Always look for the corner cases, specially in the linked list problems.
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
    return;
}

void printAllnodes(ListNode* head){
    if(head==NULL){
        return;
    }
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

// Count the no. of Nodes in a Linked List.
// iterative approach
int nodeCount(ListNode* head){
    int cnt = 0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
}

// Recursive approach
int nodeRecCount(ListNode* head){
    if(!head){
        return 0;
    }

    // int cnt = 0;
    // cnt = nodeRecCount(head->next) + 1;
    // return cnt;
    return nodeRecCount(head->next) + 1;
}

// Search for node in a Linked List.
// iterative approach
bool searchFornode(ListNode* head, int target){
    while(head){
        if(head->val == target){
            return true;
        }
        head = head->next;
    }
    return false;
}

// Recursive approach
bool searchRecFornode(ListNode* head, int target){
    if(!head){
        return false;
    }

    if(head->val == target){
        return true;
    }

    return searchRecFornode(head->next, target);
}

int main(){
    ListNode* head = new ListNode(50);
    insertAthead(head, 40);
    insertAthead(head, 30);
    insertAthead(head, 20);
    insertAthead(head, 10);

    printAllnodes(head);

    cout<<nodeCount(head)<<endl;
    cout<<nodeRecCount(head)<<endl;

    searchFornode(head, 80) ? cout<<"Ture"<<endl : cout<<"False"<<endl;
    searchRecFornode(head, 40) ? cout<<"Found!!"<<endl : cout<<"Not Found!!"<<endl; 
    return 0;
}