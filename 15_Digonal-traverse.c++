#include<iostream>
#include<vector>
using namespace std;

void digonaltraverse(vector<vector<int> > arr, int m, int n){
    
}

int main(){
    int m, n;
    cin>>m>>n;
    // int arr[m][n];
    vector<vector<int> > arr;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    digonaltraverse(arr, m, n);
    return 0;
}