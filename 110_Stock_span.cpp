// Given prices of a stock for N consecutive days, design an algorithm to find, for each day, span of stock price on that day. 
 
// We define span of stock price today as the maximum number of consecutive days ( starting from today and going backwards ) for which the stock price was less than or equal to today's price.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void solve(vector<int> v, int n){
    stack<pair<int, int> > s; // Stores the pair(price, index), it can be the solution for next day's stock price.

    for(int i=0; i<n; i++){
        while(!s.empty() and v[i]>s.top().first){
            s.pop();
        }
        if(s.empty()){
            cout<<(i+1)<<" ";
            s.push(make_pair(v[i], i));
        }
        else{
            cout<<(i - s.top().second)<<" ";
            s.push(make_pair(v[i], i));
        }
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

// 100 80 60 70 60 75 85