// diagonal traversal of element of a matrix diagonally.

// Example:-1
//  int arr[3][3]={
//         {1, 2, 3},
//         {9, 4, 5},
//         {6, 7, 8}
//     };

//  Output :- [1, 2, 9, 3, 4, 6, 5, 7, 8]

// Example:-2
//  int arr[3][3]={
//         {1, 2, 3},
//         {9, 4, 5},
//         {6, 7, 8},
//         {10, 11, 12},
//         {13, 14, 15},
//         {16, 17, 18},
//     };

//  Output :- [1, 2, 9, 3, 4, 6, 5, 7, 10, 8, 11, 13, 12, 14, 16, 15, 17, 18]

// Example:-3
// int arr[3][6]={
//         {1, 2, 3, 10, 11, 12},
//         {9, 4, 5, 13, 14, 15},
//         {6, 7, 8, 16, 17, 18}
//     };

// Output :- [1, 2, 9, 3, 4, 6, 10, 5, 7, 11, 13, 8, 12, 14, 16, 15, 17, 18]
#include<iostream>
using namespace std;

// void printdiagonal(int arr[][1000], int m, int n, int i, int j, int x){
//     int diagonalLength=x;
//     for(int k=0; k<diagonalLength; k++){
//         cout<<arr[i+k][j-k]<<" ";
//     }
// }

// void printdiagonal1(int arr[][1000], int m, int n, int i, int j, int x){
//     int diagonalLength=x;
//     for(int k=0; k<diagonalLength; k++){
//         cout<<arr[i-k][j+k]<<" ";
//     }
// }

// void diagonaltraversal(int arr[][1000], int m, int n){
//     int x=1;
//     // cout<<m<<" "<<n<<endl;
//     int j=0;
//     for(; j<min(m, n) and x<=(min(m, n)); j++){
//         if(j%2){
//             printdiagonal(arr, m, n, 0, j, x);
//         }
//         else{
//             // cout<<j<<endl;
//             printdiagonal1(arr, m, n, j, 0, x);
//         }
//         x++;
//     }
//     // cout<<j<<endl;
//     int diff=max(m, n) - min(m, n);
//     x=min(m, n)-1;
//     if(m>n){
//         for(int i=0; i<diff; i++){
//             if(j%2)
//                 printdiagonal(arr, m, n, i+1, n-1, x+1);
//             else
//                 printdiagonal1(arr, m, n, j, 0, x+1);
//             // cout<<j<<endl;
//             j++;
//         }
        
//         for(int i=diff+1; i<m and x>0; i++){
//             if(j%2)
//                 printdiagonal(arr, m, n, i, n-1, x);
//             else
//                 printdiagonal1(arr, m, n, m-1, i-diff, x);
//             x--;
//             j++;
//         }
//     }
//     x=min(m, n)-1;
//     if(n>m){
//         for(int i=0; i<diff; i++){
//             if(j%2)
//                 printdiagonal(arr, m, n, 0, x+i+1, diff);
//             else
//                 printdiagonal1(arr, m, n, m-1, i+1, diff);
//             j++;
//         }
//         for(int i=1; i<m and x>0; i++){
//             if(j%2)
//                 printdiagonal(arr, m, n, i, n-1, x);
//             else
//                 printdiagonal1(arr, m, n, m-1, j-i-1, x);
//             x--;
//             j++;
//         }
//     }
// }

// int main(){
//     // int arr[3][6]={
//     //     {1, 2, 3, 10, 11, 12},
//     //     {9, 4, 5, 13, 14, 15},
//     //     {6, 7, 8, 16, 17, 18}
//     // };
//     // diagonaltraversal(arr, 3, 6);
//     int m, n;
//     cin>>m>>n;
//     int arr[1000][1000];
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             cin>>arr[i][j];
//         }
//     }
//     diagonaltraversal(arr, m, n);
//     // cout<<endl<<arr[1][0]<<endl;
//     return 0;
// }




// int func()
// int func(){
//     cout<<"yes";
// }
// int &fun(){
//     static int x=10;
//     return x;
// }

// int main(){
//     func();
//     fun()=30;
//     cout<<fun();
//     return 0;
// }


int main() {
	// your code goes here
	int n;
    cin>>n;
    int arr[100000]={};
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
	// while(true){
	// 	cin>>n;
	// 	if(n==42) break;
	// 	cout<<n;
	// }
	// return 0;
}



// Spiral print of diagonals of a 2d matrix.


// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
        
//         vector<int> ans(m * n);
//         int index = 0;

//         int i = 0;
//         int j = 0;
//         ans[index++] = mat[i][j];

//         bool isUp = true;
//         while(index != ans.size()) {
//             if(isUp) {
//                 j += 1;

//                 while(j != 0 && i != m - 1) {
//                     if(j < n) {
//                         ans[index++] = mat[i][j];
//                     }
//                     i++;
//                     j--;
//                 }

//                 ans[index++] = mat[i][j];
//                 isUp = false;
//             } else {
//                 i += 1;

//                 while(i != 0 && j != n - 1) {
//                     if(i < m) {
//                         ans[index++] = mat[i][j];
//                     }
//                     i--;
//                     j++;
//                 }

//                 ans[index++] = mat[i][j];
//                 isUp = true;
//             }
//         }

//         return ans;
//     }
// };