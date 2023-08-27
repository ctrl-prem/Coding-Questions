#include<iostream>
#include<set>
#include<string>
using namespace std;
// char array with repetitions.
// method 1:- Using set(it only contain unique char array(string)).
// method 1:- is time consuming as we are still generating duplicate permutations.

void solve(string s, set<string>& out, int i){
    if(i==s.length()){
        out.insert(s);
        return;
    }

    for(int j=i; j<s.length(); j++){
        swap(s[i], s[j]);
        solve(s, out, i+1);
        swap(s[i], s[j]);
    }
    return;
}

void solution(string s, vector<string> &out, int i){
    if(i==s.length()){
        out.push_back(s);
        return;
    }

    for(int j=i; j<s.length(); j++){
        bool flag = true;
        for(int k=j+1; k<s.length(); k++){
            if(s[k]==s[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            swap(s[i], s[j]);
            solution(s, out, i+1);
            swap(s[i], s[j]);
        }
    }
    return;
}

int main(){
    string s;
    cin>>s;
    set<string> out;
    vector<string> out1;
    solve(s, out, 0);
    solution(s, out1, 0);
    for(auto i : out){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i : out1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}