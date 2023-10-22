// Given an array of N integers nums, design an algorithm to check if there exists a 132-Pattern in nums. We define a 132-Pattern as a subsequence of 3-integers nums[i], nums[j] and nums[k] such that  
 
// i < j < k and  
// nums[i] < nums[k] < nums[j]. 

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool solve(vector<int> nums, int n){
    vector<int> minVal(n);
    minVal[0] = nums[0];
    for(int i=1; i<n; i++){
        minVal[i] = min(minVal[i-1], nums[i]);
    }

    stack<int> s;

    for(int i=n-1; i>=0; i--){
        int help = minVal[i];
        while(!s.empty() and s.top()<=help){
            s.pop();
        }
        if(s.empty()){
            s.push(nums[i]);
        }
        else if(nums[i]>help and nums[i]>s.top()){
            return true;
        }
        else s.push(nums[i]);
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    solve(nums, n) ? cout<<"132-Pattern Exist"<<endl : cout<<"132-Pattern Not Exist"<<endl;
    return 0;
}