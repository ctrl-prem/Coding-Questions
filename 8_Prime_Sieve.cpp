// =========================================================================================
// Prime_Sieve(find the no. of prime no. between [2, n(given no.)] available and to print)

// Step1:-Take a boolean array of length n+1 and assign it as true.
// Step2:-

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool help[n+1];
    memset(help, true, sizeof(help));
    for(int i=2; i<=sqrt(n); i++){// i<=sqrt(n) coz if there is any factor of a no. present, that can be found till sqrt(n) only, otherwise there is no factor for that no.
        if(help[i]){
            for(int j=i*i; j<sizeof(help); j+=i){
                help[j]=0;
            }
        }
    }
    for(int i=2; i<n+1; i++){
        if(help[i])
            cout<<i<<" ";
    }
    return 0;
}