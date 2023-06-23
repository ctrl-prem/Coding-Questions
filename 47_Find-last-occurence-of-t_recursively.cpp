#include<iostream>
using namespace std;

int last_occurence(int *x, int i, int t){
    // base case.
    if(i==-1){
        return -1;
    }
    // recursive relation.
    if(x[i]==t){
        return i;
    }
    // friends call
    return last_occurence(x, i-1, t);
}

int main(){
    int x[]={10,20,30,20,30};
    int t=40;
    int n=5;
    cout<<last_occurence(x, n-1, t)<<endl;
    return 0;
}