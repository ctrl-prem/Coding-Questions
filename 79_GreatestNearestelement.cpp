// Greatest nearest element to the right of the every element.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void GreatestNearestElement(vector<int> a, int n){
    stack<int> s;
    vector<int> out(n);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and a[i]>s.top()){
            s.pop();
        }
        if(s.empty()){
            out[i] = -1;
            s.push(a[i]);
        }
        else{
            out[i] = s.top();
            s.push(a[i]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // vector<int> vect{ 1,2,3,4,5 };
    // vector<int> vect;
    int n;
    vector<int> vect(n);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>vect[i];
    }
    GreatestNearestElement(vect, n);
    cout<<endl;
    return 0;
}