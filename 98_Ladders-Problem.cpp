// person needs to reach nth ladder from 0th ladder. Person can take 0 to k stepa at max from current ladder. Find the maximum number of ways to reach nth ladder.

#include<iostream>
#include<vector>
using namespace std;


// printing the path using recursion. and returning the number of ways.
vector<int> help;

int solve1(int n, int i, int k){
    if(i == n){
        for(int i=0; i<help.size(); i++){
            cout<<help[i]<<" ";
        }
        cout<<endl;
        return 1;
    }
    int count = 0;
    for(int j=1; j<=k; j++){
        if(i+j <= n){
            help.push_back(i+j);
            count += solve1(n, i+j, k);
            help.pop_back();
        }
        else break;
    }
    return count;
}

// returing the no. of ways, without printing the path using recursion.
int solve(int n, int k, int i){
    if(i == n) return 1;

    int count = 0;
    for(int j=1; j<=k; j++){
        if(i+j <= n){
            count += solve(n, k, i+j);
        }
        else break;
    }
    return count;
}

// Using dp, returning the no. of ways, without printing the path using recursion.
int solveDp(int n, int k, int i, vector<int>& dp){
    // Look up
    if(dp[i] != -1) return dp[i];

    // Base case
    if(i == n) return dp[i] = 1;

    // Recursive case
    int count = 0;
    for(int j=1; j<=k; j++){
        if(i+j <= n){
            count += solveDp(n, k, i+j, dp);
        }
        else break;
    }
    return dp[i] = count;
}

int main(){
    int n; 
    cin>>n;
    int k;
    cin>>k;
    cout<<solve(n, k, 0)<<endl;

    cout<<solve1(n, 0, k)<<endl;

    vector<int> dp(n+1, -1);
    cout<<solveDp(n, k, 0, dp)<<endl;

    return 0;
}