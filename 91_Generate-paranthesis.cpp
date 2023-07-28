#include<iostream>
#include<vector>
using namespace std;

void function1(int n, char* out, int x, int y, vector<string>& ans, int i){
    // base case
    if(i == 2*n){
        out[i] = '\0';
        ans.push_back(out);
        return;
    }
    // recursive case
    if(x<n){
        out[i] = '(';
        // cout<<out<<"_";
        function1(n, out, x+1, y, ans, i+1);
    }
    // cout<<x<<"_"<<y<<"_"<<endl;
    if(y<n){
        out[i] = ')';
        // cout<<out<<"_";
        function1(n, out, x, y+1, ans, i+1);
        // cout<<"_"<<out<<endl;
    }
}

vector<string> solution(int n){
    vector<string> ans;
    // string out = "";
    char out[20];
    int x = 0, y = 0;
    int i=0;
    function1(n, out, x, y, ans, i);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> vect;
    // char out[20];
    vect = solution(n);
    for(int i=0; i<vect.size(); i++){
        cout<<vect[i]<<endl;
    }
    // cout<<endl;
    return 0;
}