// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool validChar(vector<vector<char> >& v, int n, int i, int j, char d){
    // cout<<i<<" "<<j<<" "<<d<<" "<<n;
    for(int k=0; k<n; k++){
        if(v[i][k]==d or v[k][j]==d){
            return false;
        }
    }
    int rn = sqrt(n);
    // cout<<" "<<rn;
    int Sx = (i/rn) * rn;
    // cout<<Sx<<" ";
    // cout<<Sx<<" ";
    int Sy = (j/rn) * rn;
    // cout<<Sy<<" ";
    for(int i=Sx; i<(Sx+rn); i++){
        for(int j=Sy; j<(Sy+rn); j++){
            if(v[i][j]==d){
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<char> >& v, int n, int i, int j){
    if(i==n){
        // cout<<"yes_";
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                cout<<v[x][y]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // cout<<"Yes_";

    if(j==n){
        // cout<<"Yes_"<<j;
        solve(v, n, i+1, 0);
        return;
    }
    if(v[i][j]!='.'){
        solve(v, n, i, j+1);
        return;
    }
    // cout<<"Yes_";
    for(int k=1; k<=9; k++){
        char d = k+'0';
        if(validChar(v, n, i, j, d)){
            // cout<<"yes_";
            v[i][j]=d;
            solve(v, n, i, j+1);
            v[i][j]='.';
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<char> > v(n, vector<char> (n));
    // vector<vector<int> > v(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    } 
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    solve(v, n, 0, 0);
    return 0;
}
/*
9
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

9
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
*/