// Stack implementation using array.(A fixed size stack)
// Functions included:
    // push()
    // pop()
    // size()
    // top()
    // empty()

#include<iostream>
using namespace std;

template <typename T>
class ListNode{
    public:
        T val;
        ListNode<T>* next;

        ListNode(T val){
            this->val = val;
            this->next = NULL;
        }
};

template <typename T>
class forward_list{
    ListNode<T>* head;
    T val;

    public:

        forward_list(){
            head = NULL;
        }

        forward_list(T val){
            head = new ListNode<T>(val);
        }

        void push_front(T val){
            ListNode<T>* temp = new ListNode<T>(val);
            temp->next = head;
            head = temp;
        }

        void pop_front(){
            if(!head){
                return;
            }

            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }

        T front(){
            return head->val;
        }

        bool empty(){
            if(!head){
                return true;
            }
            return false;
        }
};

template <typename T>
class stack{
    public:

        forward_list<T>* fw;
        int cnt;

        stack(){
            fw = new forward_list<T>();
            cnt = 0;
        }

        stack(T val){
            fw = new forward_list<T>(val);
            cnt = 1;
        }
        void push(T val){
            fw->push_front(val);
            cnt++;
        }
        void pop(){
            fw->pop_front();
            cnt--;
        }
        int size(){
            return cnt;
        }
        T top(){
            return fw->front();
        }
        bool empty(){
            if(fw){
                return false;
            }
            return true;
        }
};

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // printStack(st);

    cout<<st.size()<<endl;
    
}