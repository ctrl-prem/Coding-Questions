#include<iostream>
#include<string>
// #include<vector>
#include<stack>
using namespace std;

int lengthOfLastWord(string s) {
    stack<char> s1;
    int count=0;
    for(int i=0; i<s.size(); i++){
        s1.push(s[i]);
    }
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    // while(s1.top()==' ')s1.pop();
    // while(!s1.empty() && s1.top()!=' '){
    //     cout<<s1.top()<<" ";
    //     count++;
    //     s1.pop();
    // }
    return count;

}

class node {
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

void printVal(node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    node* n1=new node(10);
    insertAtHead(n1, 20);
    insertAtHead(n1, 30);
    insertAtHead(n1, 40);
    insertAtHead(n1, 50);
    insertAtHead(n1, 60);
    insertAtHead(n1, 70);

    printVal(n1);
    return 0;
}