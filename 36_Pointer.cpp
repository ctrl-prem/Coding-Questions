#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    // int t;
    // // cout<<&t<<endl;
    // char a='e';
    // char * pchar=&a;
    // cout<<pchar<<endl;
    int arr[3]={1,2,3};
    cout<<count(arr, arr+3, 4)<<endl;
    cout<<(arr+3)<<endl;
    cout<<upper_bound(arr, arr+3, 4)<<endl;
    cout<<&arr<<" "<<arr<<endl;

    // int x=133;
    // void * ptr=&x;
    // cout<<ptr<<endl;
    return 0;
}