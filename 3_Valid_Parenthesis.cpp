// Good Example that shows the importance of Stack;

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(auto i:s){
        if(i=='(' or i=='{' or i=='[') st.push(i);
        else{
            if(st.empty() or (i=='(' and i!=')') or (i=='{' and i!='}') or (i=='[' and i!=']')) cout<<false<<endl;
            st.pop();
        }
        cout<<st.empty()<<endl;
    }
    return 0;
}

// Code that will not work on a case like:- "([)]".

// class Solution {
// public:
//     bool isValid(string s) {
//         int n=s.length();
//         bool arr[10005]={};
//         for(int i=0; i<n-1; i++){
//             char c=s[i];
//             if((c==')' or c=='}' or c==']') and arr[i]==0) return false;
//             else if(arr[i]==1) continue;
//             for(int j=i+1; j<n; j++){
//                 if((c=='(' and s[j]==')') or (c=='{' and s[j]=='}') or (c=='[' and s[j]==']'))
//                 arr[i]=1;
//                 arr[j]=1;
//             }
//         }
//         for(int i=0; i<n; i++){
//             if(arr[i]==0) return false;
//         }
//         return true;
//     }
// };