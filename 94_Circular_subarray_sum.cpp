// Maximum circular subarray sum in the given array.
// e.g. 1 2 3 -2 5
// Ans: 11

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    int mini = a[0];
    int maxi = a[0];
    int min_sum = 0;
    int max_sum = 0;
    for(int i=1; i<n; i++){
        maxi = max(maxi+a[i], a[i]);
        max_sum = max(max_sum, maxi);
        min_sum = min(min_sum, mini);
        mini = min(mini+a[i], a[i]);
        mini>0?mini=0:mini;
    }
    // cout<<max_sum<<" "<<min_sum<<endl;
    cout<<max(max_sum, sum-min_sum)<<endl;
}