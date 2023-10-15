// building own forward_list class.
// functions include:
    // push_front()
    // pop_front()
    // front()

#include<iostream>
using namespace std;

// Normal class
/* class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int val){
            this->val = val;
            this->next = NULL;
        }
};

class forward_list{
    ListNode* head;
    int val;

    public:

        forward_list(){
            head = NULL;
        }

        forward_list(int val){
            head = new ListNode(val);
        }

        void push_front(int val){
            ListNode* temp = new ListNode(val);
            temp->next = head;
            head = temp;
        }

        void pop_front(){
            if(!head){
                return;
            }

            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        int front(){
            return head->val;
        }

        bool empty(){
            if(!head){
                return true;
            }
            return false;
        }
};

void printForward(forward_list fw){
    while(!fw.empty()){
        cout<<fw.front()<<" ";
        fw.pop_front();
    }
    cout<<endl;
} */

// Generic Class
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

void printForward(forward_list<int> fw){
    while(!fw.empty()){
        cout<<fw.front()<<" ";
        fw.pop_front();
    }
    cout<<endl;
}

int main(){
// for normal class
    /* forward_list fw;
    fw.push_front(10);
    fw.push_front(9);
    fw.push_front(8);
    fw.push_front(7);

    printForward(fw); */

    forward_list<int> fw;
    fw.push_front(10);
    fw.push_front(9);
    fw.push_front(8);
    fw.push_front(7);

    printForward(fw);

}