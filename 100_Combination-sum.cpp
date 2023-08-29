// Combination sum: Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. An element can be used as many times as needed.

#include<iostream>
#include<vector>
using namespace std;

void solution(vector<int> candidates, int target, vector<vector<int> >& res, vector<int> temp, int i){
    if(target == 0){
        res.push_back(temp);
        return;
    }

    for(int j=i; j<candidates.size(); j++){
        if(target - candidates[j] >= 0){
            temp.push_back(candidates[j]);
            solution(candidates, target - candidates[j], res, temp, j);
            temp.pop_back();
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> candidates(n);
    for(int i=0; i<n; i++){
        cin>>candidates[i];
    }
    int target;
    cin>>target;
    vector<vector<int> > res;
    vector<int> temp;
    solution(candidates, target, res, temp, 0);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}