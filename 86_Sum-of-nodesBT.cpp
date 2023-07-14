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

void post_order(node* root){
    // base case
    if(!root){
        cout<<-1<<" ";
        return;
    }
    // recursive case
    post_order(root->left);
    
    post_order(root->right);

    cout<<root->val<<" ";
}

void BuildTree(node* &root1){
    int val;
    cin>>val;
    if(val == -1){
        root1 = NULL;
        return;
    }
    root1 = new node(val);
    BuildTree(root1->left);
    BuildTree(root1->right);
}

int sum(node* root){
    // base case 
    if(!root) return 0;

    // recursive case
    // int x = root->val;
    // int y = sum(root->left);
    // int z = sum(root->right);
    // return (x+y+z);
    return sum(root->left) + sum(root->right) + root->val;
}

int CountNodes(node* root){
    // base case
    if(!root) return 0;

    // recursive case
    return CountNodes(root->left) + CountNodes(root->right) + 1;
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
    node* root1 = NULL;
    // BuildTree(root1);
    pre_order(root);
    // cout<<endl;
    // pre_order(root1);
    cout<<endl;
    cout<<sum(root)<<endl;
    cout<<CountNodes(root)<<endl;
    return 0;
}