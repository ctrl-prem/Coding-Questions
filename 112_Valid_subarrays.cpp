// Given an integer array nums, design an algorithm to find the number of non-empty sub-arrays with the leftmost element of the subarray not larger than other elements in the subarray. 

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int solve(vector<int> v, vector<int> fact, int n){
    stack<pair<int, int> > s;
    int cnt = 0;

    for(int i=n-1; i>=0; i--){
        while(!s.empty() and v[i]<s.top().first){
            s.pop();
        }
        if(s.empty()){
            cnt += n-i;
            s.push(make_pair(v[i], i));
        }
        else{
            cnt += s.top().second - i;
            s.push(make_pair(v[i], i));
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<int> fact(n);
    fact[0] = fact[1] = 1;
    for(int i=2; i<n; i++){
        fact[i] = i*fact[i-1];
    }

    int cnt = solve(v, fact, n);
    cout<<cnt<<endl;

    return 0;
}