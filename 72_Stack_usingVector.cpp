// Stack implementation using vector.(A dynamic size of stack)
// Functions included:
    // push()
    // pop()
    // size()
    // top()
    // empty()

#include<iostream>
using namespace std;

// Normal class of stack;
/* class stack{
    vector<int> v;

    public:

        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int size(){
            return v.size();
        }

        int top(){
            return v.back();
        }

        bool empty(){
            return v.empty();
        }
}; */

/* void printStack(stack st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
} */

// Generic class of stack;
template <typename T>
class stack{
    vector<T> v;

    public:

        void push(T val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int size(){
            return v.size();
        }

        T top(){
            return v.back();
        }

        bool empty(){
            return v.empty();
        }
};

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
} 

int main(){
// for normal class of stack;
    /* stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    printStack(st);

    cout<<st.size()<<endl; */

// for Generic class of stack;
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    printStack(st);

    cout<<st.size()<<endl;

}