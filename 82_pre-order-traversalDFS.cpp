#include<iostream>
using namespace std;

class node {
    public:
    int val;
    node* left;
    node* right;

    node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void pre_order(node* root){
    // base case
    if(!root){
        cout<<-1<<" ";
        return;
    }
    // recursive case
    cout<<root->val<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

int main(){
    node* root = NULL;
    root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(60);
    root->left->right->left = new node(70);
    
    // root->left->right->left = new node(80);

    pre_order(root);
    cout<<endl;
    return 0;
}