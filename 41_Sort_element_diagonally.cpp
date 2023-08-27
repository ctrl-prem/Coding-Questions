// 2D array always pass by reference only.
#include<iostream>
using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j);

int main(){
    int mat[10][10]={{21,12,18,16},{15,14,17,13},{19,20,11,22}};
    int m=3;
    int n=4;
    for(int i=0; i<3; i++){
        printDiagonal(mat, m, n, i, 0);
    }
    for(int j=0; j<n; j++){
        printDiagonal(mat, m, n, 0, j);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void printDiagonal(int mat[][10], int m, int n, int i, int j){
    int dLen=min(m-i, n-j);
    int arr[dLen];
    for(int k=0; k<dLen; k++){
        arr[k]=mat[i+k][j+k];
    }
    sort(arr, arr+dLen);
    for(int k=0; k<dLen; k++){
        mat[i+k][j+k]=arr[k];
    }
}