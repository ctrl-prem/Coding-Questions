// Path will be given as "NNNSWWEEE" with direction (EWNS : East, West, North, South), each char indicates the direction( with 1 unit distance travelled to that direction) We reach to our destination after travelling through given path.
// To Find, the Minimum path we should take to reach that destination from starting point.

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    int x=0, y=0;
    for(int i=0; i<str.length(); i++){
        switch(str[i]) {
            case 'E': x++; break;
            case 'W': x--; break;
            case 'N': y++; break;
            case 'S': y--; break;
        }
    }
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;

    str = "";
    if(x<0){
        for(int i=0; i<((-1)*x); i++){
            str+='W';
        }
    }
    else {
        for(int i=0; i<(x); i++){
            str+='E';
        }
    }
    if(y<0){
        for(int i=0; i<((-1)*y); i++){
            str+='S';
        }
    }
    else {
        for(int i=0; i<(y); i++){
            str+='N';
        }
    }
    cout<<str<<endl;
    return 0;
}