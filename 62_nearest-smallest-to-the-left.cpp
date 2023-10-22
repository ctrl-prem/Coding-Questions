// time complexity should be not greater than O(n).
// given an integer array.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void solve(vector<int> v, int n){
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.empty()){
            cout<<-1<<" ";
            s.push(v[i]);
        }
        else if(v[i]<s.top()){
            while(!s.empty() and s.top()>v[i]){
                s.pop();
            }
            if(s.empty()) cout<<-1<<" ";
            else cout<<s.top()<<" ";
            s.push(v[i]);
        }
        else{
            cout<<s.top()<<" ";
            s.push(v[i]);
        }
    }
    cout<<endl;
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