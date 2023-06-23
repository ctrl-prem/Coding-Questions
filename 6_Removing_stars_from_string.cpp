// 2390(leetcode):- Removing Stars from the string with a character just in left of it.

#include<iostream>
#include<cstring>
using namespace std;

// Using Two Pointers Approach.

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int j=0;
    for(int i=0; i<n; i++){
        if(s[i]=='*'){
            j--;
        }
        else{
            s[j++]=s[i];
        }
    }
    cout<<s<<endl;
    return 0;
}