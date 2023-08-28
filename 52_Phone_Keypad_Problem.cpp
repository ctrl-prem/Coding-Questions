#include<iostream>
#include<string>
#include<vector>
using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solution(string s, vector<string>& out, string help, int i, string keypad[]){
    if(i==s.length()){
        out.push_back(help);
        return;
    }

    string str = keypad[s[i]-'0'];
    for(int j=0; j<str.length(); j++){
        help.push_back(str[j]);
        solution(s, out, help, i+1, keypad);
        help.pop_back();
    }
    return;
}

int main(){
    string s;
    cin>>s;
    vector<string> out;
    // vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solution(s, out, "", 0, keypad);
    for(auto x: out){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}