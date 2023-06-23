#include<iostream>
#include<climits>
using namespace std;

int main(){
    /* Approach #0 :- Using brute force method in n^(3) TC(Time Complexity). */


    int n;
    cout<<endl;
    cin>>n;
    int arr[n];
    // int arr[5]={-3, 2, -1, 4, -5};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    /* Approach #1 Kadane's Algorithm*/
    
    int max_sum=INT_MIN;
    int sum=0;
    // for(int i=0; i<n; i++){
    //     sum+=arr[i];
    // }
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>max_sum){
            max_sum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<max_sum<<endl<<endl;


    /* Approach #2 :- Cumulative Sum Method */
    // here we create an array(length 1 more than the given array) and store cumulative sum accordingly to that and to find the sum_ij, we use the method sum_ij=csum[j+1]-csum[i]; T.C.=O(n^2) with S.C.=O(n+1).

    return 0;
}

/*
-2 1 -3 4 -1 2 1 -5 4
*/