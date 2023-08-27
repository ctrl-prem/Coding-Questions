#include<iostream>
using namespace std;

int main(){
    // int n;
    // cin>>n;
    int *ptr = new int;
    *ptr=10;
    int *ptr1 = new int;
    *ptr1=*ptr;
    *ptr1 = *ptr1 + 2;
    cout<<*ptr1<<endl;
    cout<<*ptr<<endl;
}