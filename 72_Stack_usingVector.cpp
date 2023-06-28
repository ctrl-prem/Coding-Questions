// Implementing stack with dynamic size, using vector-DataStructure.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class stack {
    public:
    vector<T> v;
    void push(T data){
        v.push_back(data);
    }
    void pop(){
        if(!v.empty())
            v.pop_back();
    }
    int size(){
        return v.size();
    }
    T top(){
        return v.back(); //v[v.size()-1];
    }
    bool empty(){
        return v.empty();
    }
};

int main(){
    stack<string> s1;
    s1.push("re");
    s1.push("r p");
    s1.push("ma");
    s1.push("ku");
    s1.push("em ");
    s1.push("pr");
    cout<<s1.size()<<endl;
    while(!s1.empty()){
        cout<<s1.top();
        s1.pop();
    }
    cout<<endl<<s1.empty()<<endl;
    return 0;
}