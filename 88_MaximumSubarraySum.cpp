#include<iostream>
#include<vector>
using namespace std;


// Method 1:
// T.C. - O(n^3)
int MaximumSubarraySum(vector<int> v, int n){
    int max_sum = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += v[k];
            }
            if(sum>max_sum) max_sum = sum;
        }
    }
    return max_sum;
}

// Method 2:
// T.C. - O(n^2)
int MaxiSubSum(vector<int> v, int n){
    int max_sum = INT_MIN;
    vector<int> csum(n+1);
    csum[0] = 0;
    for(int i=1; i<=n; i++){
        csum[i] = csum[i-1] + v[i-1];
    }
    // for(int i=0; i<=n; i++) cout<<csum[i]<<" ";
    // cout<<endl;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum = csum[j+1] - csum[i];
            if(sum > max_sum) max_sum = sum;
        }
    }
    return max_sum;
}

// Method 3:
// T.C. - O(n) Kadane's Algorithm
int KadaneMaxSum(vector<int> v, int n){
    int maxi = INT_MIN;
    int max_sum = v[0];
    for(int i=1; i<n; i++){
        max_sum = max(max_sum + v[i], v[i]);
        if(maxi<max_sum) maxi = max_sum;
    }
    return maxi;
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int sum = MaximumSubarraySum(v, n);
    cout<<sum<<endl;
    sum = MaxiSubSum(v, n);
    cout<<sum<<endl;

    sum = KadaneMaxSum(v, n);
    cout<<sum<<endl;
    return 0;
}