#include<iostream>
using namespace std;

string spellingMap[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void spell(int d){
    if(d==0){
        return;
    }
    
    spell(d/10);
    int n=d%10;
    cout<<spellingMap[n]<<" ";
    // if(n==1){
    //     cout<<"zero ";
    // }
    // else if(n==1){
    //     cout<<"one ";
    // }
    // else if(n==2){
    //     cout<<"two ";
    // }
    // else if(n==3){
    //     cout<<"three ";
    // }
    // else if(n==4){
    //     cout<<"four ";
    // }
    // else if(n==5){
    //     cout<<"five ";
    // }
    // else if(n==6){
    //     cout<<"six ";
    // }
    // else if(n==7){
    //     cout<<"seven ";
    // }
    // else if(n==8){
    //     cout<<"eight ";
    // }
    // else if(n==9){
    //     cout<<"nine ";
    // }
}

int main(){
    int n;
    cin>>n;
    spell(n);
    return 0;
}