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
}

void bubble_sort(node* &head){
    node* temp = head;
    int n = size(head)-1;
    while(n--){
        bool flag = true;
        for(int i=0; i<n; i++){
            node* help = head;
            if(help->val > help->next->val){
                swap(help, help->next);
                if(flag){
                    node* h2 = NULL;
                    h2 = temp->next->next;
                    temp->next = temp;
                    temp = 
                }
            }
            help = help->next;
        }
    }





}







int main(){
    node* head = new node(50);
    head->insertAtHead(40, head);
    head->insertAtHead(30, head);
    head->insertAtHead(20, head);
    head->insertAtHead(10, head);
    head->print(head);
    cout<<endl;
    bubble_sort(head);
    head->print(head);
    cout<<endl;
    return 0;
}