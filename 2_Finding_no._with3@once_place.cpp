// Find Out in the array if there is sum of three no.s that have 3 at their once place.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Total no. of Test Cases: ";
    cin>>t;
    for(int i=0; i<t; i++){
        int s;
        string ans="No";
        cout<<"Enter the length of your array: ";
        cin>>s;
        cout<<endl;
        vector<int> a(10, 0);
        int e; //elements
        for(int j=0; j<s; j++){
            cout<<"Enter the element at "<<j<<"th index: ";
            cin>>e;
            a[e%10]++;
        }
        /* Used frequency concept here (storing only the once place values each for 
        3 times as we are only taking sum of three numbers.)*/
        cout<<endl;
        vector<int> help;
        for(int n=0; n<10; n++){
            for(int j=0; j<min(a[n], 3); j++){
                // cout<<n<<endl;
                help.push_back(n);
            }
        }
        
        int a1, a2, a3;
        int m=help.size();
        // cout<<m<<endl;
        for(int j=0; j<m-2; j++){
            a1=help[j];
            // cout<<a1<<endl;
            for(int k=j+1; k<m-1; k++){
                a2=help[k];
                for(int l=k+1; l<m; l++){
                    a3=help[l];
                    int sum=a1+a2+a3;
                    // cout<<sum<<endl;
                    if(sum%10==3){
                        ans="Yes";
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
// Time Limit Exceeded