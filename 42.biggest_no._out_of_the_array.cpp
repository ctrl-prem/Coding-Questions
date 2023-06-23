#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool sortforbiggest(string s1, string s2){
    if(s1+s2>s2+s1){
        return true;
    }
    else return false;
}

int main(){
    int n;
    cin>>n;
    string str[n];
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    sort(str, str+n, sortforbiggest);
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}