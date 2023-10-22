// time complexity should be not greater than O(n).

// Ques :- Maximum Area Rectangle in a Binary Matrix. (leetcode)

// given an integer array.
// Solve using deque as well.
// Given an array of N integers representing heights of bars in a histogram where width of each bar is a 1 unit, design an algorithm to find the area of the largest rectangle in the histogram. 

// Input: heights = [2,1,5,6,2,3]
// Output: 10

#include<iostream>
#include<stack>
#include<deque>
#include<vector>
using namespace std;

int solution(vector<int> v, int n){
    deque<pair<int,int> > s;
    vector<int> v_l;
    deque<int> v_r;

    for(int i=0; i<n; i++){
        while(!s.empty() and s.back().first>=v[i]){
            s.pop_back();
        }
        if(s.empty()){
            s.push_back(make_pair(v[i], i));
            v_l.push_back(0);
        }
        else{
            v_l.push_back(s.back().second+1);
            s.push_back(make_pair(v[i], i));
        }
    }

    s.clear();

    for(int i=n-1; i>=0; i--){
        while(!s.empty() and s.back().first>=v[i]){
            s.pop_back();
        }
        if(s.empty()){
            s.push_back(make_pair(v[i], i));
            v_r.push_front(n-1);
        }
        else{
            v_r.push_front(s.back().second-1);
            s.push_back(make_pair(v[i], i));
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, (v_r[i]-v_l[i]+1)*v[i]);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans = solution(v, n);
    cout<<ans<<endl;
    return 0;
}