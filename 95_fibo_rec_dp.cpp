// find nth fibonacci no. using recursion and dp

#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &dp){
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n==0 or n==1){
        return dp[n] = n;
    }
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<solve(n, dp)<<endl;
    return 0;
}