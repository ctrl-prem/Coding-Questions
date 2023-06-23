#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str[n];
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    string ans=" ";

    for(int i=0; i<n; i++){
        if(str[i]>ans){
            ans=str[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}