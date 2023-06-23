#include<iostream>
using namespace std;

void printSpiral(int arr[][1000], int m, int n){
    int r=0, d=0, l=n-1, u=m-1;
    while(r<d){
        cout<<
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    int arr[1000][1000];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    printSpiral(arr, m, n);
    return 0;
}