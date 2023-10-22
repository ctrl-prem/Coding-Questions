// Given an integer array asteroids representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left).  
 
// Assuming all the asteroids move at the same speed, find out the state of the asteroids after all the collisions such that when two asteroids meet or collide, the smaller one will explode and if both of the asteroids are of the same size then both of them will explode.   
 
// Also, two asteroids moving in the same direction will never meet.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void solve(vector<int> v, int n){
    stack<int> s;
    vector<int> out;
    
    for(int i=0; i<n; i++){
        int help = v[i];
        while(!s.empty() and v[i]<0 and s.top()>0 and help!=0){
            if(s.top()==abs(v[i])){
                s.pop();
                help = 0;
            }
            else if(s.top()<abs(v[i])){
                s.pop();
            }
            else{
                help = 0;
            }
        }
        if(help != 0){
            s.push(help);
        }
    }

    while(!s.empty()){
        out.push_back(s.top());
        s.pop();
    }
    reverse(out.begin(), out.end());
    for(auto x : out){
        cout<<x<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    solve(v, n);
    return 0;
}