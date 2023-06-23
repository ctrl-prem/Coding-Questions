#include<iostream>
using namespace std;

void convert(string str, int n){

}

int main(){
    // string str="xaxbxc";
    // cin>>str;
    // int n=str.size();
    // convert(str, n);

    // char ch[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    // char ch1[2][2]="abcd";  //{{'a','b'},{'c','d'}};
    // char c[2][2]={{'a','b'},{'c','d'}};
    // char c1[2][2]={{'a','b'},{'c','d'}};
    // cout<<(c==c1)<<endl; //array comparison always evaluates to false.
    // cout<<(ch>ch1)<<endl; //not allowed in 2d array.
    // reverse(ch.begin(), ch.end());
    // cout<<ch<<endl;
    string s1="kumar";
    string s2="kumar";
    cout<<s1.compare(s2)<<endl; // Here, s1 compare with s2 character-by-character and on finding unequal character It return int(s2 char)-int(s1 char). and if all characters are same return 0.
    cout<<(s1>s2)<<endl;
    return 0;
}