// Given an integer array nums ( 0-indexed ), find the maximum possible score of a subarray.  
 
// We define score of a subarray nums [i…j] as min (nums [i], …, nums [j]) * j-i+1. 

// Example : 1 4 3 7 5 0
// output : 12

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int Solution(vector<int> v, int n){
    int ans = 0;
    stack<pair<int, int> > s;
    vector<int> v_l;
    vector<int> v_r;

    for(int i=0; i<n; i++){
        while(!s.empty() and s.top().first>=v[i]){
            s.pop();
        }
        if(s.empty()){
            s.push(make_pair(v[i], i));
            v_l.push_back(0);
        }
        else{
            v_l.push_back(s.top().second+1);
            s.push(make_pair(v[i], i));
        }
    }

    while(!s.empty()){
        s.pop();
    }
// [6569,9667,3148,7698,1622,2194,793,9041,1670,1872]
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and s.top().first>=v[i]){
            s.pop();
        }
        if(s.empty()){
            s.push(make_pair(v[i], i));
            v_r.push_back(n-1);
        }
        else{
            v_r.push_back(s.top().second-1);
            s.push(make_pair(v[i], i));
        }
    }

    reverse(v_r.begin(), v_r.end());
    // for(int x:v_r) cout<<x<<" ";
    // cout<<endl;

    for(int i=0; i<n; i++){
        ans = max(ans, (v_r[i]-v_l[i]+1)*v[i]);
    }

    return ans;
}
// [6569,9667,3148,7698,1622,2194,793,9041,1670,1872]
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans = Solution(v, n);
    cout<<ans<<endl;
    return 0;
}