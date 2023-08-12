// Task: given no. of painter = p, and an array size = n(no. of boards array[i] = length of ith board). we need to find the minimum time in which all boards can be painted. time = length. a board only be painted by a single painter.


#include <iostream>
#include <vector>
using namespace std;

bool possible(int m, vector<int> a, int p, int n){
    int cnt = 1;
    int time = 0;
    for(int i=0; i<n; i++){
        if(time+a[i]<=m){
            time += a[i];
        }
        else{
            cnt++;
            if(cnt>p or a[i]>m){ 
                // cout<<"No"<<endl;
                return false;
            }
            time = a[i];
        }
    }
    // cout<<"Yes"<<endl;
    return true;
}

int time_required(int p, vector<int> a, int n){
    int s = a[0]; // s is the min time may be required to paint all the given boards.
    // int s = 0;
    for(int i=1; i<n; i++){
        s = max(s, a[i]); // if(a[i]>s) s = a[i];
    }
    // s max of array, as we can take painters equal to the size of the given array.
    int e = a[0]; // e is the max time may be required to paint all the given boards.
    for(int i=1; i<n; i++){
        e += a[i]; // we can combine this loop with the above loop.
    }
    // e is the sum of length of all the given boards.
    int m = s + (e-s)/2;
    int ans = INT_MAX;
    while(s<=e){
        if(possible(m, a, p, n)){
            ans = min(ans, m);
            // cout<<m<<" "<<e<<" "<<s<<endl;
            e = m-1;
        }
        else s = m+1;   
        m = s + (e-s)/2;
        // cout<<"_"<<m<<endl;
    }
    return ans;
}

int main(){
    int p;
    cin>>p;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int t = time_required(p, a, n);
    cout<<t<<endl;
    return 0;
}