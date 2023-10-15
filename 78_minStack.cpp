// We need to form a Stack class, such that it return min. value of stack whenever asked for it @ constant(O(1)) time.

#include<iostream>
#include<list>
#include<stack>
using namespace std;

// template <typename T>
// class stack1{
//     list<T> l1;
//     stack<int> s;
//     // int cnt;

//     public:

//         void push(T val){
//             l1.push_front(val);
//             if(s.empty() or val<=s.top()){
//                 s.push(val);
//             }
//         }

//         void pop(){
//             if(l1.empty()){
//                 return;
//             }

//             if(l1.front()==s.top()){
//                 s.pop();
//             }

//             l1.pop_front();
//         }

//         T top(){
//             l1.front();
//         }

//         int size(){
//             return l1.size();
//         }

//         bool empty(){
//             return l1.empty();
//         }

//         T minStack(){
//             return s.top();
//         }
// };

// void allMinStack(stack1<int> st){
//     while(!st.empty()){
//         cout<<st.minStack()<<" ";
//         st.pop();
//     }
//     cout<<endl;
// }

template <typename T>
class stack1{
    stack<int> s;
    int minValue;

    public:

        void push(T val){
            if(s.empty()){
                minValue = val;
                s.push(val);
            }
            else if(val<minValue){
                s.push(2*val - minValue);
                minValue = val;
            }
            else s.push(val);
        }

        void pop(){
            if(s.empty()){
                return;
            }
            if(s.top()<minValue){
                minValue = 2*minValue - s.top();
            }
            s.pop();
        }

        T top(){
            return (s.top()<minValue) ? minValue : s.top();
        }

        int size(){
            return s.size();
        }

        bool empty(){
            return s.empty();
        }

        T minStack(){
            return minValue;
        }
};

void allMinStack(stack1<int> st){
    while(!st.empty()){
        cout<<st.minStack()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack1<int> st;
    st.push(10);
    st.push(3);
    st.push(50);
    st.push(2);
    st.push(1);
    st.push(0);

    cout<<st.minStack()<<endl;
    allMinStack(st);
    return 0;
}