// make a binary/recursion tree of the solution.

#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
    int mid=s+(e-s)/2;
    // int *temp=new int[];
    int temp[100];
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid and j<=e){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int l=s; l<=e; l++){
        arr[l]=temp[l];
    }
}

void mergesort(int* arr, int s, int e){
    // base case;
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    // recursive case;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr, s, e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}