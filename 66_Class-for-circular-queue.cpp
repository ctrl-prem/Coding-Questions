// As memory get wasted in simple(implementation of queue using an array) queue. As we can't insert in full queue even we get space after deleting element from front of the queue. To overcome this wastage of memory we can implement a circular queue, that will use the space after deletion to store more element(s).

#include<iostream>
using namespace std;

template <typename T>
class queue{
    public:
        T *arr;
        int t;
        int p;
        int n;
        int cnt;

        queue(int n){
            arr = new T[n+1];// n+1 size implies we can initialize t and p with zero.
            t = 0;
            p = 0;
            cnt = 0;
            this->n = n+1;
        }

        void push(T val){
            if((t+1)%n == p){
                return;
            }
            t = (t+1)%n;
            arr[t] = val;
            cnt++;
        }

        void pop(){
            if(p==t){
                return;
            }
            p = (p+1)%n;
            cnt--;
        }

        T front(){
            return arr[(p+1)%n];
        }
        
        int size(){
            return cnt;
        }

        bool empty(){
            return t==p;
        }
};

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print(q);

    q.pop();

    print(q);
    q.push(60);
    print(q);

    q.pop();

    q.push(70);

    print(q);
    
    return 0;
}