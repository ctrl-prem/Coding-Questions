// make the binary/recursion tree of the solution. Solve using pivot.

#include<iostream>
using namespace std;

int findpivot(vector<int>& vect, int s, int e){
    int i=s, j=s-1;
    while(i<e){
        if(vect[i]<vect[e]){
            j++;
            swap(vect[i], vect[j]);
        }
        i++;
    }
    swap(vect[++j], vect[e]);
    return j;
}

void QuickSort(vector<int>& vect, int s, int e){
    // base case
    if(s>=e) return;
    // Recursive case
    int p = findpivot(vect, s, e);
    QuickSort(vect, s, p-1);
    QuickSort(vect, p+1, e);
}

int main(){
    vector<int> vect;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        vect.push_back(a);
    }
    QuickSort(vect, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    return 0;
}