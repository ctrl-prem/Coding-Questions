#include<iostream>
using namespace std;
int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bool flag=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(flag!=true){
            cout<<"reached"<<endl;
            break;
        }
    }
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}