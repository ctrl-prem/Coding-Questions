// Stack implementation using array.(A fixed size stack)
// Functions included:
    // push()
    // pop()
    // size()
    // top()
    // empty()

#include<iostream>
using namespace std;

// Normal Class of Stack;
/*class stack{
    int* arr;
    int t;
    int n;

    public:
        stack(int n){
            arr = new int[n];
            t = -1;
            this->n = n; // "this" is a pointer to object we called, and to reach to that object we can simply dereference "this" in any methods of class we require.
        }

        void push(int val){
            if(t == n-1){
                return;
            }
            t = t+1;
            arr[t] = val;
        }

        void pop(){
            t = t-1;
        }

        int size(){
            return t+1;
        }

        int top(){
            return arr[t];
        }

        bool empty(){
            if(t == -1){
                return true;
            }
            return false;
        }
}; */

// Generic Class for a Stack;
template <typename T>
class stack{
    T* arr;
    int t;
    int n;

    public:
        stack(int n){
            arr = new T[n];
            t = -1;
            this->n = n; // "this" is a pointer to object we called, and to reach to that object we can simply dereference "this" in any methods of class we require.
        }

        void push(T val){
            if(t == n-1){
                return;
            }
            t = t+1;
            arr[t] = val;
        }

        void pop(){
            t = t-1;
        }

        int size(){
            return t+1;
        }

        T top(){
            return arr[t];
        }

        bool empty(){
            if(t == -1){
                return true;
            }
            return false;
        }
};

// For Normal class of Stack
/* void printStack(stack st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
} */

// for generic class of Stack
void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
} 

int main(){
// for normal class of stack
    /* stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    printStack(st);

    cout<<st.size()<<endl; */

// for generic class of stack
    stack<int> st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    printStack(st);

    cout<<st.size()<<endl;

}