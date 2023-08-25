#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool sortforbiggest(string s1, string s2){ // ex: str[n] = {"54", "546", "548", "60"}. here at every point we take two strings and compare them. if s1+s2>s2+s1 then we return true else false. for example first we take s1 = "54" and s2 = "546" and compared that "54546" > "54654" which is true so we return true. then we take s1 = "54" and s2 = "548" and compared that "54548" > "54854" which is true so we return true. then we take s1 = "54" and s2 = "60" and compared that "5460" > "6054" which is false so we return false. then we take s1 = "546" and s2 = "548" and compared that "546548" > "548546" which is false so we return false. then we take s1 = "546" and s2 = "60" and compared that "54660" > "60546" which is false so we return false. then we take s1 = "548" and s2 = "60" and compared that "54860" > "60548" which is false so we return false. so the final array will be {"60", "548", "546", "54"}. It completed in O(nlogn) time complexity. Explaination for the time complexity is given below.
// Time Complexity: O(nlogn) because we are using sort function which takes O(nlogn) time complexity.
// And the sort function uses quick sort algorithm which takes O(nlogn) time complexity.
// And the quick sort algorithm uses divide and conquer method which takes O(nlogn) time complexity.
// And the divide and conquer method uses recursion which takes O(nlogn) time complexity.
// And the recursion uses stack which takes O(nlogn) time complexity.

    if(s1+s2>s2+s1){
        return true;
    }
    else return false;
}

int main(){
    int n;
    cin>>n;
    string str[n];
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    sort(str, str+n, sortforbiggest);
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}