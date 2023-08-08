#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int>& A, vector<int>& B){
    vector<int> ans;
    int n = B.size();
    int sum_A = 0;
    for(int i=0; i<n; i++){
        sum_A += A[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        int x = B[i];
        cnt = (x/sum_A)*n;
        sum = cnt*sum_A;

    }
    for(int i=0; i<B.size(); i++){
        int x = B[i];
        int j=0;
        int sum = 0;
        int count = 0;
        while(true){
            sum+=A[j];
            count++;
            if(sum >= x){
                ans.push_back(count);
                break;
            }
            if(j == n-1){
                if(sum<=0){
                    ans.push_back(-1);
                    break;
                }
                j = 0;
                continue;
            }
            j++;
        }
    }
    return ans;
}

int main(){
    // vector<int> A;
    // for(int i=0; i<3; i++){
    //     int x;
    //     cin>>x;
    //     A.push_back(x);
    // }
    // vector<int> B;
    // for(int i=0; i<3; i++){
    //     int x;
    //     cin>>x;
    //     B.push_back(x);
    // }
    // vector<int> answer = solve(A, B);
    // for(int i=0; i<answer.size(); i++){
    //     cout<<answer[i]<<" ";
    // }
    // cout<<endl;
    // return 0;
    cout<<(20%3==0)<<endl;
}