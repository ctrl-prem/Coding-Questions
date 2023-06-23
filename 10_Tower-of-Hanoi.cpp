// make a binary/recursion tree of the solution.

#include<iostream>
using namespace std;

int cnt=0;

void f(int n, char curr, char help, char dest){
    // Base case;
    if(n==0) return;
    // Recursive case;
    f(n-1, curr, dest, help);
    cout<<"Move the disk from "<<curr<<" to "<<dest<<endl;
    cnt++;
    f(n-1, help, curr, dest);
    // return;
}

int main(){
    int n;
    cin>>n;
    f(n, 'A', 'B', 'C');
    cout<<cnt<<endl;
    return 0;
}