// Given an array of integers and a target t. we need to print all the possible combinations that sum up to t. we can use a no. infinite time.
// example:
/*  4
    7
    2 3 5 7
    2 2 3
    2 5 
    7       */
#include<iostream>
#include<vector>
using namespace std;

void solution(int t, vector<int> arr, vector<int> out, int i){
    if(t==0){
        for(int j=0; j<out.size(); j++){
            cout<<out[j]<<" ";
        }
        cout<<endl;
        return;
    }

    int n = arr.size();
    for(int j=i; j<n; j++){
        if(t-arr[j]>=0){
            out.push_back(arr[j]);
            solution(t-arr[j], arr, out, j);
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
    solution(t, arr, out, 0);
    return 0;
}