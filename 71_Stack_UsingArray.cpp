#include<iostream>
using namespace std;

class stack {
    public:
    int* arr; //int arr[1000]; // we used "int* arr" coz we can have the value of n at runtime.
    int t;
    int n;
    stack(int n){
        arr = new int[n]; //creating an array of fixed size on heap.
        // if we have used "int arr[1000];" then there is no need for "arr = new int[n];"
        t = -1;
        this->n = n;
    }
    void push(int val){
        if(t != n-1){
            arr[++t] = val;
        }
    }
    void pop(){
        if(t != -1) t--;
    }
    int top(){
        return arr[t];
    }
    int size(){
        return t+1; //currently the no. of values, stack is having.
    }
    bool empty(){
        if(t == -1) return true;
        return false;
    }
};

int main(){
    stack s1(5);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    cout<<s1.empty()<<endl;

    return 0;
}