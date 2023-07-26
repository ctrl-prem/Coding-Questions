#include<iostream>
#include<string>
using namespace std;

void coinToss(string str, int n, int i){
    // base case
    if(i>=n){
        cout<<str<<endl;
        return;
    }
    // recursive case
    str.push_back('H');
    coinToss(str, n, i+1);
    str.pop_back();
    str.push_back('T');
    coinToss(str, n, i+1);
}

int main(){
    int n;
    cin>>n;
    string str = "";
    coinToss(str, n, 0);
    return 0;
}