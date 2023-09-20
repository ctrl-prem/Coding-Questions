// Using mid =s+(e-s)/2;

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(vector<int> arr, int s, int e){
    if(s>e){
        return 0;
    }
    int mid = s+(e-s)/2;
    return solve(arr, s, mid-1) + arr[mid] + solve(arr, mid+1, e);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = solve(arr, 0, n-1);
    cout<<sum<<endl;
    return 0;
}