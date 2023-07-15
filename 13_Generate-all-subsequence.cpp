// Generate all subsequences and print it in sorted order. Given a string.
// Identify the backtracking part in it.
// make a binary/recursion tree of the solution.
#include<iostream>
#include<vector>
using namespace std;


// Iterative Approach

// vector<int> out;

void GenerateAllSubsequence(vector<int> v, int n){
    for(int i=0; i<(1<<n); i++){
        vector<int> out;
        for(int j=0; j<n; j++){
            if((i>>j)&1){
                out.push_back(v[j]);
            }
        }
        for(int j=0; j<out.size(); j++) cout<<out[j]<<" ";
        cout<<endl;
    }
    return;
}

int main(){
    vector<int> v;
    int n=1;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<v.back()<<endl;
    GenerateAllSubsequence(v, n);
    // cout<<endl;
    return 0;
}