// person needs to reach nth ladder from 0th ladder. Person can take 0 to k stepa at max from current ladder. Find the maximum number of ways to reach nth ladder.

#include<iostream>
#include<vector>
using namespace std;

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

int main(){
    int n; 
    cin>>n;
    int k;
    cin>>k;
    cout<<solve(n, k, 0)<<endl;
    cout<<solve1(n, 0, k)<<endl;
    return 0;
}