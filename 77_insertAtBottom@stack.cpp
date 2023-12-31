// 1. Solve using another stack;
// 2. Solve within the given stack;

#include<iostream>
#include<stack>
// #include<iterator>
using namespace std;

// 1. Using another stack;
void Atbottom(stack<int> &s, int val){
    stack<int> st;
    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }
    s.push(val);
    while(!st.empty()){
        s.push(st.top());
        st.pop();
    }
}

// Within the stack, using recursion.
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

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    print(s);

    int val;
    cin>>val;
    // Atbottom(s, val);
    AtbottomRec(s, val);
    print(s);
    return 0;
}