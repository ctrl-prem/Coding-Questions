#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void insertAtBottom(stack<int> &s, int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }
    // recursive case
    int a = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(a);
}

void reverse(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    // recursive case
    int x = s.top();
    s.pop();

    reverse(s);

    insertAtBottom(s, x);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    print(s);

    reverse(s);
    print(s);
    
    int x = 0;
    insertAtBottom(s, x);
    print(s);

    reverse(s);
    print(s);

    return 0;
}