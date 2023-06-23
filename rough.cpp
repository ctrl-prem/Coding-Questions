#include<iostream>
#include<string>
// #include<vector>
#include<stack>
using namespace std;

int lengthOfLastWord(string s) {
    stack<char> s1;
    int count=0;
    for(int i=0; i<s.size(); i++){
        s1.push(s[i]);
    }
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    // while(s1.top()==' ')s1.pop();
    // while(!s1.empty() && s1.top()!=' '){
    //     cout<<s1.top()<<" ";
    //     count++;
    //     s1.pop();
    // }
    return count;

}


int main(){
	string s;
    // s="i am prem kumar  ";
    getline(cin, s); //can't use cin>>s as it will not consider the space as input it will terminate just after the space entered. 
    int cnt=  lengthOfLastWord(s); cout<<cnt<<endl; }