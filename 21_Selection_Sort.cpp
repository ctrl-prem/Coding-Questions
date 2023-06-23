#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        int cp=i;
        for(int j=i+1; j<n; j++){
            if(arr[cp]>arr[j]){
                cp=j;
            }
        }
        swap(arr[cp], arr[i]);
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}