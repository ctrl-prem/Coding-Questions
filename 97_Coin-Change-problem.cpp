// Minimum no. of coin required to reduce the amount to 0 using the given coins in the array

#include<iostream>
#include<vector>
using namespace std;

// Method 1: Memoization Solution top-down
int solution(int n, vector<int> a, vector<int>& dp){
    // look up
    if(dp[n]!=-1){
        return dp[n];
    }
    // base case
    if(n==0){
        return dp[n]=0;
    }
    // recursive case
    int ans = INT_MAX;
    for(int i=0; i<a.size(); i++){
        if(n-a[i]>=0){
            ans = min(ans, solution(n-a[i], a, dp));
        }
    }
    return dp[n] = ans == INT_MAX ? ans: ans + 1;
}

// Method 2: Bottom-up Solution tabulation
int solve1(int n, vector<int>& a){
    vector<int> dp(n+1, -1);
    int k = a.size();
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int ans = INT_MAX;
        for(int j=0; j<k; j++){
            if(i-a[j]>=0){
                ans = min(ans, dp[i-a[j]]);
            }
        }
        dp[i] = ans == INT_MAX ? ans : ans + 1;
    }
    return dp[n];
}

// Method 3: Recursive Solution
int solve(int n, vector<int>& a){
    // base case
    if(n==0) return 0;

    // Recursive Case
    int c = INT_MAX;
    for(int i=0; i<a.size(); i++){
        if(n-a[i]>=0){
            c = min(c, solve(n-a[i], a));
        }
    }
    return c==INT_MAX?c:c+1;
}

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> a(x);
    for(int i=0; i<x; i++){
        cin>>a[i];
    }
    vector<int> dp(n+1, -1);

    int z = solve(n, a); // recursive
    z == INT_MAX ? cout<<-1<<endl : cout<<z<<endl;

    int y = solution(n, a, dp); // top-down
    y == INT_MAX ? cout<<-1<<endl : cout<<y<<endl;

    int b = solve1(n, a); // bottom-up
    b == INT_MAX ? cout<<-1<<endl : cout<<b<<endl;

    return 0;
}