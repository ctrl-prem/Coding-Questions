// DNF_Sorting is used to sort an array having 3 known values only.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int start=-1, mid=0, last=n;
    for(; mid<last; ){
        if(arr[mid]==0){
            swap(arr[start+1], arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[last-1], arr[mid]);
            last--;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}