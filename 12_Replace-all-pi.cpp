// replace all the "pi" with "3.14" in the given string.
// make the binary/recursion tree of the solution.
#include<iostream>
#include<string>
using namespace std;

void replacepi(string& str, int i){
    // base case


    // recursive case
    if(str[i]=='p' and str[i+1]=='i'){
        int j = i+2;
        while(j!='\0') j++;
        while(j>=i+2){
            str[j+2] = str[j];
            j--;
        }
        str[i] = '3';
        str[i+1] = '.';
        str[i+2] = '1';
        str[i+3] = '4';
        replacepi(str, i+4);
    }
    else{
        replacepi(str, i+1);
    }
}

int main(){
    string str;
    cin>>str;
    replacepi(str, 0);
    cout<<str<<endl;
    return 0;
}