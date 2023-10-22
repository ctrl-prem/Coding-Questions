// time complexity should be not greater than O(n).
// given an integer array.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void solve(vector<int> v, int n){
    stack<int> s;

    vector<int> out;
    for(int i=n-1; i>=0; i--){
        if(s.empty()){
            out.push_back(-1);
            s.push(v[i]);
        }
        else if(s.top()>v[i]){
            while(!s.empty() and s.top()>v[i]){
                s.pop();
            }
            if(s.empty()) out.push_back(-1);
            else out.push_back(s.top());
            s.push(v[i]);
        }
        else{
            out.push_back(s.top());
            s.push(v[i]);
        }
    }
    for(int i = out.size()-1; i>=0; i--){
        cout<<out[i]<<" ";
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