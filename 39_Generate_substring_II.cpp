// generate substrings length wise.
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s="abcde";
    int l=s.length();
    for(int i=0; s[i]!='\0'; i++){
        for(int j=0; j<l-i; j++){
            cout<<s.substr(j, i+1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}