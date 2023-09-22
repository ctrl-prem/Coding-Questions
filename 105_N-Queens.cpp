// N-Queens problem, Given N no. of Queens and we need to place all Queens in ("n x n" matrix)(we will deal with a matrix without actual formation of it.) in a way such that they do not attack each other.
// i.e.,
// No two Queens should be in same vertical column and neither in same diagonal(left and right diagonals).

#include<iostream>
#include<vector>
using namespace std;

void solve(int n, vector<int>& pos, int r, vector<vector<string> >& ans){
    if(r==n){
        vector<string> help;
        for(int i=0; i<pos.size(); i++){
            string s(n, '.');
            s[pos[i]] = 'Q';
            // cout<<s<<endl;
            // cout<<pos[i]<<" ";
            help.push_back(s);
        }
        ans.push_back(help);
        // cout<<endl;
        return;
    }

    for(int i=0; i<n; i++){
        bool validPos = true;
        for(int j=0; j<r; j++){
            if(pos[j]==i or pos[j]==i-(r-j) or pos[j]==i+(r-j)){
                validPos = false;
                break;
            }
        }
        if(validPos){
            pos[r]=i;
            solve(n, pos, r+1, ans);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<string> > ans;
    vector<int> pos(n);
    solve(n, pos, 0, ans);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            string s = ans[i][j];
            for(int k=0; k<n; k++){
                cout<<s[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}