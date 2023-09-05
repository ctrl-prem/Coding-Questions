#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x){
    string str = to_string(n);
    string ans;
    int i = 0;
    int j = str.length()-1;
    x = x%str.length();
    for(int i=0; i<str.length(); i++){
        if(j-i>=x){
            ans.push_back(str[i+x]);
        }
        else{
            ans.push_back(str[x-(j-i)-1]);
        }
    }
    return stoi(ans);
}

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int ans = solve(n, x);
    cout<<ans<<endl;
    return 0;
}