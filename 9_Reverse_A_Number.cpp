// Reverse a Number.
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p=0;
    while(n>0){
        p=p*10+(n%10);
        n/=10;
    }
    cout<<p<<endl;
    return 0;
}