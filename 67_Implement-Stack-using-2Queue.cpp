#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class stack{
    queue<T> q1;
    queue<T> q2;

    public:
        void push(T val){
            if(!q2.empty()){
                q2.push(val);
            }
            else{
                q1.push(val);
            }
        }

        void pop(){
            if(!q1.empty()){
                while(!q1.empty()){
                    T val = q1.front();
                    q1.pop();
                    if(!q1.empty()){
                        q2.push(val);
                    }
                }
            }
            else if(!q2.empty()){
                while(!q2.empty()){
                    T val = q2.front();
                    q2.pop();
                    if(!q2.empty()){
                        q1.push(val);
                    }
                }
            }
        }

        T top(){
            while(!q1.empty()){
                T val = q1.front();
                q1.pop();
                q2.push(val);
                if(q1.empty()){
                    return val;
                }
            }
            while(!q2.empty()){
                T val = q2.front();
                q2.pop();
                q1.push(val);
                if(q2.empty()){
                    return val;
                }
            }
        }

        int size(){
            if(!q1.empty()){
                return q1.size();
            }
            return q2.size();
        }

        bool empty(){
            if(!q1.empty() or !q2.empty()){
                return false;
            }
            return true;
        }
};

void print(stack<int> &st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(4);
    // st.pop();
    // cout<<st.top()<<endl;

    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
    print(st);
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}