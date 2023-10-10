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

ListNode* kthNode(ListNode* head, int k){
    ListNode* temp = head;
    for(int i=1; temp and i<k; i++){
        temp = temp->next;
    }

    if(!temp) return NULL;

    while(temp->next){
        temp = temp->next;
        head = head->next;
    }

    return head;
}

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    int k;
    cin>>k;
    ListNode* result = kthNode(head, k);
    !result ? cout<<"No"<<endl : cout<<result->val<<endl;
    return 0;
}