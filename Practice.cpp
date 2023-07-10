#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
// string spellmap[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// void spell(int n){
//     // base case
//     if(n==0){
//         return;
//     }
//     //friend's task
//     spell(n/10);
//     //my task
//     cout<<spellmap[n%10]<<" ";
//     return;
// }

// int main(){
//     int n;
//     cin>>n;
//     spell(n);
//     cout<<endl;
//     return 0;
// }


// *2->String To Integer

// int s_to_i(string str){
//     //base case
//     if(str==""){
//         return 0;
//     }
//     //friend's task
//     //my task
//     return (s_to_i(str.substr(0, str.length()-1))*10)+(str[str.length()-1]-'0');
// }

// int main(){
//     string str="8374";
//     int l=0;
//     cout<<s_to_i(str);
//     cout<<endl;
//     return 0;
// }

// *3-> Move x to the end.

// string Move(string str, string &ans){
//     // base case
//     if(str=="")return ans;
//     // friend's case
//     // Move(str.substr(0, str.length()-1), ans);
//     // my case
//     if(str[str.length()-1]=='x'){
//         ans+='x';
//     }
//     else{
//         ans=str[str.length()-1]+ans;
//     }
//     // cout<<ans<<endl;
//     return Move(str.substr(0, str.length()-1), ans);
// }

// int main(){
//     // string str;
//     // cin>>str;
//     // string ans="";
//     // cout<<Move(str, ans)<<endl;
//     // cout<<endl;
//     string str="prem";
//     cout<<str.substr(0, 1);
//     return 0;
// }

// Question:- matrix with 0 and X .
// int main(){
// 	int t;
//     cin>>t;
//     while(t--){
//         int n, m;
//         cin>>n>>m;
//         int cnt=0;
//         int x1, y1, x2, y2;
//         cin>>x1>>y1>>x2>>y2;
//         if(x1==1 or x1==n){
//         }
//     }
//     return 0;
// }


// Q:- How 1-D array comparison works?
// // Sol:- say char array ch="abc" and ch1="abxyz", comparison will start, Like it takes 1st character of arrays here 'a' and 'a' and convert it into int and than "substract" if on substration(if strcmp(ch, ch1)=> 1st char of ch i.e., 'a'-'a'(1st char of ch1)) is 0 than will proceed further upto, where it get difference (!=0) and print, else it will print 0.
// int main(){
//     char ch[5]="pve2";
//     char ch1[5]="pxe";
//     // for(int i=0; i<5; i++){
//     //     cin>>ch[i];
//     // }
//     strcpy(ch, ch1);
//     strcat(ch, ch1);
//     cout<<strcmp(ch, ch1)<<endl;
//     cout<<ch<<endl;
//     return 0;
// }

// #Note:- Logical Operators, only work for string not for character array.


// Ques:- String Tokenization

// int main(){
//     string str="pre";
//     string str1="pm4";
//     cout<<str.compare(str1)<<endl;
//     cout<<(str<str1)<<endl;
// }

int main() {
    int n;
    vector<int> A(n);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int a = 0, b = 0, c = 0;
    // sort(A.begin(), A.end());
    for(int i=0; i<n; i++) cout<<A[i]<<" ";
    // for(auto x:A) cout<<x<<" ";
    // cout<<endl;
    // int n1 = A.size();
    // cout<<n1<<endl;
    // // int n1 = A.size();
    // // cout<<n1<<endl;
    // // cout<<n1<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<"hello"<<endl;
    //     if(A[i]>=a){
    //         cout<<"entered "<<endl;
    //         c = b;
    //         b = a;
    //         a = A[i];
    //     }
    //     // else if(A[i]>b){
    //     //     c = b;
    //     //     b = A[i];
    //     // }
    //     // else if(A[i]>c){
    //     //     c = A[i];
    //     // }
    // }
    // cout<<(a + b + c)<<endl;
}