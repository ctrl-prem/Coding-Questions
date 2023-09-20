// Generate all palandromic substrings from a given substring.

#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string str;
    cin>>str;
    int cnt=0;
    string out = "";
    int n = str.size();
    for(int i=0; i<n; i++){
        int j=0;
        out = "";
        while(i-j>=0 and i+j<n){
            if(str[i-j]==str[i+j]){
                if(j==0) out += str[i-j];
                else out = str[i-j]+out+str[i-j];
                cnt++;
                cout<<out<<" ";
            }
            else break;
            j++;
        }
    }
    for(float i=0.5; i<n; i++){
        float j=0.5;
        out = "";
        while(i-j>=0 and i+j<n){
            if(str[int(i-j)]==str[int(i+j)]){
                out = str[int(i-j)]+out+str[int(i-j)];
                cnt++;
                cout<<out<<" ";
            }
            else break;
            j++;
        }
    }
    cout<<endl<<cnt<<endl;
    return 0;
}