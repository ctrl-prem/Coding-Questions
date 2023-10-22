// Solve the problem in O(n) T.C.
// Nearest greater of every value of a given array to it's right.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void solve(vector<int> v, int n){

    /* here we can use any container other stack that follow the same operations to complete this problem.*/
    stack<int> s; // Stack is required, As stored number is changing every time and the new number depends on previous stored number.


    vector<int> out; // As output will be in reverse order.

    for(int i=n-1; i>=0; i--){
        while(!s.empty() and v[i]>s.top()){
            s.pop();
        }
        if(s.empty()){
            // cout<<-1<<" ";
            out.push_back(-1);
            s.push(v[i]);
        }
        else{
            // cout<<s.top()<<" ";
            out.push_back(s.top());
            s.push(v[i]);
        }
    }
    reverse(out.begin(), out.end());
    for(int i=0; i<n; i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    solve(v, n);
    return 0;
}