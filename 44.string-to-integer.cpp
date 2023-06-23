#include<iostream>
using namespace std;

int stringToInteger(string str, int n){
    if(n==0){ // str.empty() or str.size()==0 or str=="";
        return 0;
    }
    string substring=str.substr(0, n-1);
    int ans=stringToInteger(substring, n-1);
    return ans*10+str[n-1]-'0';
}

int main(){
    string str;
    cin>>str;
    int n =str.size();
    int integer=stringToInteger(str, n);
    cout<<integer+1<<endl;
    return 0;
}