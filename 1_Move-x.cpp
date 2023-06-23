#include<iostream>
#include<string>
using namespace std;

string movex(string s){
    // base case;
    if(s.empty())
        return "";
    // recursive relation
    string stringfromfriend=movex(s.substr(1));//substring starting from index=1;
    string ch=s.substr(0,1);
    if(ch=="x"){
        return stringfromfriend+ch;
    }
    return ch+stringfromfriend;
}

int main(){
    string s;
    cin>>s;
    cout<<movex(s)<<endl;
    return 0;
}