// Counting Sort in Stable(relative order of elements remain same) Form.
// T.C. for this sorting is O(n) and S.C. for this sorting is O(k)(coz we are taking an array of K+1 length).

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // k = no. upto which, we have no. in the given array starting from the 0(zero).
    int k;
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    
    int cnt[k+1];
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++){
        // cout<<arr[i]<<"_c ";
        cnt[arr[i]]++;
        // cout<<cnt[arr[i]]<<"_h  ";
    }

    // cout<<endl;

    // for(int i=0; i<=k; i++){
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<endl;

    // Cumulative sum of the count.
    for(int i=1; i<=k; i++){
        cnt[i]+=cnt[i-1];
    }

    // for(int i=0; i<=k; i++){
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<endl;

    for(int i=k; i>0; i--){
        cnt[i]=cnt[i-1];
    }

    cnt[0]=0;
    int ans[n];
    for(int i=0; i<n; i++){
        ans[cnt[arr[i]]]=arr[i];
        cnt[arr[i]]++;
    }

    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}