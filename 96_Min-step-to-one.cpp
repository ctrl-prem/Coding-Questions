// Given a no. N, You have 3 operations to reduce N to 1
// 1. N = N/3 if N%3 == 0
// 2. N = N/2 if N%2 == 0
// 3. N = N-1
// Find the min no. of operations required to reduce N to 1


// Recursive Approach
#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    // Base Case
    if(n==1){
        return 0;
    }
    // Recursive Case
    int x = solve(n-1);
    int y = INT_MAX;
    if(n%2==0){
        y = solve(n/2);
    }
    int z = INT_MAX;
    if(n%3==0){
        z = solve(n/3);
    }
    return min(x, min(y,z))+1;
}
// Time Complexity: O(3^n)
// Space Complexity: O(n) (Stack Space)/(function call stack)

// Top Down Approach (using Memoization)
int solution(int n, vector<int> &dp){
    // dp[i] stores the min no. of operations required to reduce i to 1
    // memset(dp, -1, sizeof(dp));
    // memoization
    if(dp[n]!=-1){
        return dp[n];
    }
    // Base Case
    if(n==1){
        return dp[n] = 0;
    }
    // Recursive Case
    int x = solve(n-1);
    int y = INT_MAX;
    if(n%2==0){
        y = solve(n/2);
    }
    int z = INT_MAX;
    if(n%3==0){
        z = solve(n/3);
    }
    return dp[n] = min(x, min(y,z))+1;
}
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n) (dp array + function call stack)

int main(){
    int n; 
    cin>>n;
    cout<<solve(n)<<endl;
    vector<int> dp(n+1, -1);
    cout<<solution(n, dp)<<endl;
    return 0;
}