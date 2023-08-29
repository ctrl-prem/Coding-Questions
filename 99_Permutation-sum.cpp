// Permutation sum : Given an array of integers, find all combinations of elements that add to a given target. The same number may be chosen from the array an unlimited number of times.
// Input: 2 3 6 7
// Target: 7
// Output: 2 2 3, 7

#include<iostream>
#include<vector>
using namespace std;

void solution(vector<int>arr, int target, vector<int> temp, vector<vector<int> >& res){
    if(target==0){
        res.push_back(temp);
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(target-arr[i]>=0){
            temp.push_back(arr[i]);
            solution(arr, target-arr[i], temp, res);
            temp.pop_back();
        }
    }
    return;
}

int main(){
    int n, target;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>target;
    vector<vector<int> > res;
    vector<int> temp;
    solution(arr, target, temp, res);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
