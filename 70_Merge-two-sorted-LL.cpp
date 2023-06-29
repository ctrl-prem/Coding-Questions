#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* temp=new node(val);
    temp->next=head;
    head=temp;
}

void printLL(node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

node* merge(node* head1, node* head2){
    node* temp1=new node(0);
    node* temp=temp1;
    while(head1 and head2){
        if(head1->val<head2->val){
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
        }
        else{
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
    }
    while(head1){
        temp->next=head1;
        temp=temp->next;
        head1=head1->next;
    }
    while(head2){
        temp->next=head2;
        temp=temp->next;
        head2=head2->next;
    }
    return temp1->next;
}


int main(){
    node* head1= new node(50);
    node* head2=new node(60);

    insertAtHead(head1, 30);
    insertAtHead(head1, 10);
    insertAtHead(head2, 40);
    insertAtHead(head2, 20);

    node* head=NULL;
    head=merge(head1, head2);
    printLL(head);
    return 0;
}