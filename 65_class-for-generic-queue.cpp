// Generic Class of a Queue
// Some of the functions of queues are:
    // push()
    // pop()
    // empty()
    // size()
    // front()

// using array.
#include<iostream>
using namespace std;

template <typename T>
class queue{
    public:
        T* arr;
        int n;
        int p;
        int t;

        queue(int n){
            arr = new T[n];
            p = -1;
            t = -1;
            this->n = n;
        }

        void push(T val){
            if(t<n-1){
                arr[++t] = val;
            }
        }

        void pop(){
            if(t==p) return;
            p++;
        }

        bool empty(){
            return (t==p);
        }

        T front(){
            return arr[p+1];
        }

        int size(){
            return t-p;
        }
};

void printAll(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q(5);
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    q.pop();
    q.pop();
// below will not be pushed to queue even after popping, coz of size_bound.
    q.push(0);
    q.push(84);

    cout<<q.front()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;

    printAll(q);
    return 0;
}