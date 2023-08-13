// Good subarray is the array if the sum of the elements is divisible by an integer n.
// Find the number of good subarrays in the given array.

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> a, int n, int s){
    int count = 0;
    vector<int> prefix(s);
    prefix[0] = a[0];
    for(int i = 1; i < s; i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    vector<int> mod(n, 0);
    for(int i = 0; i < s; i++){
        mod[((prefix[i]%n)+n)%n]++;
    }
    for(int i = 0; i < n; i++){
        if(mod[i] > 1){
            count += (mod[i]*(mod[i]-1))/2;
        }
    }
    count += mod[0];
    return count;
}

int main(){
    int s;
    cin >> s;
    vector<int> a(s);
    for(int i = 0; i < s; i++){
        cin >> a[i];
    }
    int n;
    cin >> n;
    cout<<solve(a, n, s)<<endl;
    return 0;
}