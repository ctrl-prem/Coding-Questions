// Trapping rain water : water at building depends on the buildings height to their left and right side buildings.

#include<iostream>
using namespace std;

int trap(int * height, int n);
int solution_2(int * height, int n);

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<trap(arr, n)<<endl;
    cout<<solution_2(arr, n)<<endl;
    return 0;
}

int trap(int * height, int n) {
    int ans=0;
    int ls[n];
    int rs[n];
    ls[0]=0;
    rs[n-1]=0;
    for(int i=1; i<n; i++){
        ls[i]=max(ls[i-1], height[i-1]);
    }
    for(int i=n-2; i>=0; i--){
        rs[i]=max(rs[i+1], height[i+1]);
    }
    for(int i=0; i<n; i++){
        if((min(ls[i], rs[i])-height[i])>0){
            ans+=min(ls[i], rs[i])-height[i];
        }
    }
    return ans;

}

// Approach #2 : This approach is more effective as it do not use any extra space.
int solution_2(int * height, int n){
    int ans=0;
    int ls=INT_MIN;
    int rs=INT_MIN;
    int i=0;
    int j=n-1;
    while(i<=j){
        ls=max(ls, height[i]);
        rs=max(rs, height[j]);
        if(ls<=rs){
            int w_i=ls-height[i];
            ans+=w_i;
            i++;
        }
        else{
            int w_j=rs-height[j];
            ans+=w_j;
            j--;
        }
    }
    return ans;
}

