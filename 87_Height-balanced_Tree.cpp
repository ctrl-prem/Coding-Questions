#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(TreeNode* root){
    // base case
    if(!root) return -1;
    // recursive case
    return max(height(root->left)+1, height(root->right)+1);
}

bool CheckHeightBalanced(TreeNode* root){
    // base case
    if(!root) return true;
    // recursive case
    bool x = CheckHeightBalanced(root->left);
    bool y = CheckHeightBalanced(root->right);
    bool z = abs(height(root->left)-height(root->right))<=1 ? true : false;
    return x and y and z;
}

pair<bool, int> CheckHeightBalancedEfficient(TreeNode* root){
    // base case
    pair<bool, int> p;
    if(!root){
        p.first = true;
        p.second = -1;
        return p;
    }
    // recursive case
    pair<bool, int> pL = CheckHeightBalancedEfficient(root->left);
    pair<bool, int> pR = CheckHeightBalancedEfficient(root->right);
    abs(pL.second - pR.second)<=1 ? p.first=true : p.first = false;
    p.second = max(pL.second+1, pR.second+1);
    return p;
}

class p{
    public:
    bool isBalanced;
    int height;
};

p ClassHeightBalanced(TreeNode* root){
    // base case
    p Pair;
    if(!root){
        Pair.isBalanced = true;
        Pair.height = -1;
        return Pair;
    }
    // recursive case
    p x = ClassHeightBalanced(root->left);
    p y = ClassHeightBalanced(root->right);
    abs(x.height - y.height)<=1 ? Pair.isBalanced = true : Pair.isBalanced = false;
    Pair.height = max(x.height+1, y.height+1);
    return Pair;
}

int main(){
    TreeNode* root = NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->left->right->left = new TreeNode(70);
    root->left->right->left->left = new TreeNode(80);

    CheckHeightBalanced(root)? cout<<"Tree is Height Balanced"<<endl : cout<<"Tree is not height balanced"<<endl;

    pair<bool, int> pp;
    pp = CheckHeightBalancedEfficient(root);
    pp.first ? cout<<"Height Balanced"<<endl : cout<<"!Height Balanced"<<endl;

    p Pair = ClassHeightBalanced(root);
    Pair.isBalanced ? cout<<"Height is Balanced"<<endl : cout<<"Height is not Balanced"<<endl;
    return 0;
}