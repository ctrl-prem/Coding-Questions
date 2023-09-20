// Given an array of integers and a target t. we need to print all the possible permutations that sum up to t. we can use a no. infinite time.
// example:
/*  4
    7
    2 3 5 7
    2 2 3 
    2 3 2 
    2 5 
    3 2 2 
    5 2 
    7 */

#include<iostream>
#include<vector>
using namespace std;

void solution(vector<int> arr, vector<int>out, int t){
    if(t==0){
        for(int i=0; i<out.size(); i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
        return;
    }

    int n = arr.size();
    for(int j=0; j<n; j++){
        if(t-arr[j]>=0){
            out.push_back(arr[j]);
            solution(arr, out, t-arr[j]);
            out.pop_back();
        }
    }
}

int main(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> out;
    solution(arr, out, t);
    return 0;
}