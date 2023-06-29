// Bubble Sort over a Linked List. Used swapping.

#include<iostream>
using namespace std;

class node {
    public:
    int val;
    node* next;

    node(int val){
        this->val = val;
        this->next = NULL;
    }

    void insertAtHead(int val, node* &head){
        node* temp = new node(val);
        temp->next = head;
        head = temp;
    }

    void print(node* head){
        node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};
int size(node* head){
    int ans=0;
    while(head){
        ans++;
        head = head->next;
    }
    return ans;
}

void bubble_sort(node* &head){
    int n = size(head);
    int i=1;
    while(i<n){
        node* prev = NULL;
        node* curr = head;
        
        int j=0;
        while(j<n-i){
            node* temp = curr->next;
            if(curr->val > temp->val){
                curr->next = temp->next;
                temp->next = curr;
                if(!prev){
                    head = temp;
                }
                else prev->next = temp;
                prev = temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            j++;
        }
        i++;
    }
}

int main(){
    node* head = new node(10);
    head->insertAtHead(20, head);
    head->insertAtHead(30, head);
    head->insertAtHead(40, head);
    head->insertAtHead(50, head);
    head->print(head);
    cout<<endl;
    bubble_sort(head);
    head->print(head);
    cout<<endl;
    int n = size(head)-1;
    bool flag = true;
    node* head1 = head;


    
    head->print(head);
    cout<<endl;
    return 0;
}