// Good Example that shows the importance of Stack;

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(auto i:s){
        if(i=='(' or i=='{' or i=='[') st.push(i);
        else{
            if(st.empty() or (i==')' and st.top()!='(') or (i=='}' and st.top()!='{') or (i==']' and st.top()!='[')){
                break;
            }
            st.pop();
        }
        // cout<<st.empty()<<endl;
    }
    cout<<st.empty()<<endl;
    return 0;
}