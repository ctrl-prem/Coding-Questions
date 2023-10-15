// Reverse using iterative and recursive both approaches.

#include<iostream>
#include<stack>
using namespace std;

void AtbottomRec(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int d = s.top();
    s.pop();
    AtbottomRec(s, val);

    s.push(d);
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void reverseStack(stack<int> &s){
    if(s.size()==1 or s.empty()){
        return;
    }

    int d = s.top();
    s.pop();

    reverseStack(s);
    AtbottomRec(s, d);
}

stack<int> reverseIt(stack<int> s){
    stack<int> st;
    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }
    return st;
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    print(s);
    reverseStack(s);
    print(s);
    cout<<endl;
    s = reverseIt(s);
    print(s);
    return 0;
}