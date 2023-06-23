#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;//size of the array.
    int arr[n];//condition: Array should be sorted.
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int a;
    cin>>a; //element to search in the array.
    int s=0;
    int e=n-1;
    int mid=(e-s)/2+s;
    bool flag=false;
    while(s<e){
        if(arr[mid]==a){
            flag=true;
            cout<<"Element found "<<arr[mid];
            break;
        }
        else if(arr[mid]>a){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(e-s)/+s;
    }
    if(!flag){
        cout<<"Element not found "<<-1;
    }
    return 0;
}