#include<iostream>
#include<forward_list>
using namespace std;


int main(){
    forward_list<int> l1;
    l1.push_front(5);
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    cout<<"data of head Node :- "<<l1.front()<<endl;
    int size = distance(l1.begin(), l1.end());
    cout<<"size of LL :- "<<size<<endl;
    l1.pop_front();
    for(auto it = l1.begin(), end = l1.end(); it!=end; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // reverse(l1.begin(), l1.end()); // this syntax is not correct here.
    l1.reverse();
    for(int x : l1){
        cout<<x<<" ";
    }
    cout<<endl;
    l1.sort();
    // sort(l1.begin(), l1.end()); // this syntax is not correct here.
    for(int x : l1){
        cout<<x<<" ";
    }
    cout<<endl;
    l1.reverse();
    for(int x : l1){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<l1.empty()<<endl;
    l1.clear();
    cout<<l1.empty()<<endl;
    return 0;
}