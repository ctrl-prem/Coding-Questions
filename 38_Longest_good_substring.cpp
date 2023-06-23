#include<iostream>
#include<cstring>
using namespace std;

bool correct(string s);

int main(){
    string str="cbaeicdeiou";
    // cin>>str;
    // getline(cin, str); //For white spaces to be entered.
    // int l=str.length();
    int maxi=0;
    for(int i=0; str[i]!='\0'; i++){
        for(int j=i; str[j]!='\0'; j++){
            string s=str.substr(i, j-i+1);
            if(correct(s)){
                maxi=max(maxi, j-i+1);
            }
        }
    }
    cout<<maxi<<endl;
    return 0;
}

bool correct(string s){
    for(int i=0; s[i]!='\0'; i++){
        if(!(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')) return false;
    }
    return true;
}

// int main(){
//     string s="cbaeicdeiou";
//     int maxi=0;
//     int cnt=0;
//     for(int i=0; s[i]!='\0'; i++){
//         if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
//             cnt++;
//             if(cnt>maxi){
//                 maxi=cnt;
//             }
//         }
//         else{
//             cnt=0;
//         }
//     }
//     cout<<"length of the maximum length good substring is: "<<maxi<<endl;
// }