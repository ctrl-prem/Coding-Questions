// Find all occurences of target t, in a given integer array.

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> v, int i, int t){
    if(i==v.size()){
        return;
    }
    if(v[i]==t){
        cout<<i<<" ";
    }
    solve(v, i+1, t);
}

int main(){
    int n;
    int t;
    cin>>t;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    solve(v, 0, t);
    return 0;
}