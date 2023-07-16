// DNF_Sorting is used to sort an array having 3 known values only.

// It is used to sort container with three different elements(can be integer or any).
// introducing first, mid, and last positions, 
// where first shows area for 'first type of element' ,
// mid shows 'second type of element' or 'area of unknown element at same time' and 
// last shows 'third type of element'.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int first=-1, mid=0, last=n;
    for(; mid<last; ){
        if(arr[mid]==0){
            swap(arr[++first], arr[mid]);
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[--last], arr[mid]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}