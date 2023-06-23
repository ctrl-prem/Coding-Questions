#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // int ans[n];
    int cnt=0;
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if((i>>j)&1){
                cout<<arr[j]<<" ";
                
            }
        }
        cout<<endl;
        cnt++;
    }
    cout<<cnt;
    return 0; 
}