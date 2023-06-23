// Product of array except self in T.C.=O(n) with S.C.=O(n) and without using division operator.


#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ls[n];
    int rs[n];
    ls[0]=1;
    for(int i=1; i<n; i++){
        ls[i]=arr[i-1]*ls[i-1];
    }
    rs[n-1]=1;
    for(int i=n-2; i>=0; i--){
        rs[i]=arr[i+1]*rs[i+1];
    }
    for(int i=0; i<n; i++){
        cout<<ls[i]*rs[i]<<" ";
    }
    // cout<<endl;
    // int p=1;
    // for(int i=0; i<n; i++){
    //     p*=arr[i];
    // }
    // for(int i=0; i<n; i++){
    //     cout<<p/arr[i]<<" ";
    // }
    return 0;
}