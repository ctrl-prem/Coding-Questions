// First Non-Repeating Character in a Stream 
 
// Given a stream of characters, design an algorithm to find, for each character, first non-repeating character in the stream. 
 
// Note : output -1 if upon reading a character there are no non-repeating characters in the stream. 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    char n;
    vector<int> v(26, 0);
    queue<char> q;

    while(true){
        cin>>n;
        v[n-'a']++;
        q.push(n);
        while(!q.empty() and v[q.front() - 'a']>1){
            q.pop();
        }

        if(q.empty()){
            cout<<-1<<" ";
        }
        else{
            cout<<q.front()<<" ";
        }
    }
    return 0;
}