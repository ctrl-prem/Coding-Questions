// You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

// A 0-indexed string num of length n + 1 is created using the following conditions:

// num consists of the digits '1' to '9', where each digit is used at most once.
// If pattern[i] == 'I', then num[i] < num[i + 1].
// If pattern[i] == 'D', then num[i] > num[i + 1].
// Return the lexicographically smallest possible string num that meets the conditions.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool flag = true;
vector<bool> used(10, false);
// Here we are iterating all the loops in sorted order, hence we are getting the smallest number(the very first number.)
// Else another way is store all possible outcomes to a set and the first will be the smallest(as set stores in sorted order).
void solution(string& out, string s, int i){
    if(i==s.size()+1){
        flag = false;
        return;
    }
    if(i==0){
        for(int j=1; j<=9; j++){
            out.push_back(j+'0');
            used[j]=true;
            solution(out, s, i+1);
            if(!flag) return;
            used[j]=false;
            out.pop_back();
        }
        return; //As i==0 when we return back from recursion calls then going ahead will not make any point to go further.
    }
    int x = out.back()-'0';
    if(s[i-1]=='I'){
        for(int j=x+1; j<=9; j++){
            if(!used[j]){
                out.push_back(j+'0');
                used[j]=true;
                solution(out, s, i+1);
                if(!flag) return;
                used[j]=false;
                out.pop_back();
            }
        }
    }
    else{
        for(int j=x-1; j>0; j--){
            if(!used[j]){
                out.push_back(j+'0');
                used[j]=true;
                solution(out, s, i+1);
                if(!flag) return;
                used[j]=false;
                out.pop_back();
            }
        }
    }
}

int main(){
    string s;
    cin>>s;
    string out = "";
    solution(out, s, 0);
    cout<<out<<endl;
    return 0;
}