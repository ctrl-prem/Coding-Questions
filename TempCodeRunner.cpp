#include<iostream>
#include<cstring>
using namespace std;

void printing(int *arr){
    for(int i=0; i<sizeof(arr[0]); i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    cout<<endl;
    //size_t only store unsigned integers. 
    // size_t a=3; //== unsigned long long a=3;
    // a*=10000000;
    // cout<<sizeof(a)<<"B = "<<bitset<64>(a)<<endl;
    // char a;
    // cin>>a;
    // cout<<a<<endl<<int('a')<<endl;
    // int x=128;
    // char * ch= (char*)(&x);
    // cout<<(int)(*ch)<<endl;
    // char a='P';
    // cout<<(int*)&a<<endl;
    // int arr[5]={1,2,3,4,5};
    // printing(arr);
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    cout<<*(*arr+1)<<" "<<arr<<endl;
    // cout<<arr[0]<<endl;
    cout<<endl;
    return 0;

}