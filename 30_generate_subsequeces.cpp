
// Given relative order should remain same of all the elements of the given array/vector.

#include <iostream>
#include <vector>
using namespace std;

// Iterative Approach
void subsequences(vector<int> v, int n){
    int a = pow(2, n); // total no. of subsequences possible.
    int cnt = 0;
    for(int i=0; i<a; i++){
        vector<int> out;
        for(int j=0; j<n; j++){
            if((i>>j)&1) out.push_back(v[j]);
        }
        cnt++;
        for(int k=0; k<out.size(); k++){
            cout<<out[k]<<" ";
        }
        cout<<endl;
    }
    cout<<cnt<<endl;
}

// Recursive Approach
void rec_subseq(vector<int> v, vector<int> out, int i){
    // base case
    if(i>=v.size()){
        for(int j=0; j<out.size(); j++){
            cout<<out[j]<<" ";
        }
        cout<<endl;
        return;
    }

    // recursive case
    out.push_back(v[i]);
    rec_subseq(v, out, i+1);
    out.pop_back();
    rec_subseq(v, out, i+1);
}

int main(){
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    // subsequences(v, n);
    // cout<<endl;
    vector<int> out;
    rec_subseq(v, out, 0);
    return 0;
}