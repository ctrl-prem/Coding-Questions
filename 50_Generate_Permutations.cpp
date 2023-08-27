#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solution(string s, vector<string> &out, int i){
    // Base Case
    if(i==s.length()){
        out.push_back(s);
        return;
    }

    // Recursive Case
    for(int j=i; j<s.length(); j++){
        swap(s[i], s[j]);
        solution(s, out, i+1);
        swap(s[i], s[j]); // Backtracking step to restore the original string for next iteration of loop.
    }
}

int main(){
    string s;
    cin>>s;
    vector<string> out;
    solution(s, out, 0);
    for(string i : out){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}