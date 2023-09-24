// Always look for the corner cases, that may lead to an error.(like -> LL is empty, your program is out of range of LL, having only one node.)

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

// Insertion of Nodes in a Linked List, For different positions.
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

ListNode* getTailadd(ListNode* head){
    while(head->next!=NULL){
        head = head->next;
    }
    return head;
}

void insertAttail(ListNode* &head, int val){
    ListNode* temp = new ListNode(val);
    if(head == NULL){
        head = temp;
        return;
    }
    ListNode* temp1 = getTailadd(head);
    temp1->next = temp;
    return;
}

ListNode* getPrev(ListNode* head, int idx){
    for(int i=1; i<idx and head!=NULL; i++){
        head = head->next;
    }
    return head;
}

void insertAtindex(ListNode* &head, int val, int idx){
    if(idx==0){
        insertAthead(head, val);
        return;
    }
    ListNode* temp = new ListNode(val);
    ListNode* prev = getPrev(head, idx);
    if(prev==NULL){
        return;
    }
    temp->next = prev->next;
    prev->next = temp;
    return;
}

// Deletion of Nodes from different positions in a Linked List.
void deletionAthead(ListNode* &head){
    if(head == NULL){
        return;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
}

ListNode* getTailadd1(ListNode* head){
    while(head->next->next!=NULL){
        head = head->next;
    }
    return head;
}

void deletionAttail(ListNode* &head){
    if(head==NULL) return;
    if(head->next == NULL){
        deletionAthead(head);
        return;
    }
    ListNode* pos = getTailadd1(head);
    ListNode* temp = pos->next;
    pos->next = NULL;
    delete temp;
}

void deletionAtindex(ListNode* &head, int idx){
    if(idx==0){
        deletionAthead(head);
        return;
    }
    ListNode* prev = getPrev(head, idx);
    if(prev==NULL or prev->next==NULL){
        return;
    }
    ListNode* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

int main(){
    // ListNode* head = new ListNode(10);
    ListNode* head = NULL;
// insertion at head.
    insertAthead(head, 20);
    insertAthead(head, 30);
    insertAthead(head, 40);
    insertAthead(head, 50);
    insertAthead(head, 60);
// insertion at Tail.
    insertAttail(head, 40);
    insertAttail(head, 50);
    insertAttail(head, 60);
// insertion at index.
    insertAtindex(head, 1, 3);
    insertAtindex(head, 2, 0);
    insertAtindex(head, 1, 12);

    printAllnodes(head);

// Deletion at head
    deletionAthead(head);

// Deletion at Tail
    deletionAttail(head);

// Deletion at index
    deletionAtindex(head, 3);
    deletionAtindex(head, 0);
    deletionAtindex(head, 12);
    printAllnodes(head);
    return 0;
}