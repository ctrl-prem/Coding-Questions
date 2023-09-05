// Implimentation of graph using hash table.
// i.e., here we will represent the vertices by the key of the hash table and the edges between them by the value of the hash table. Not by the indices of the array.

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class graph{
    bool isDir;
    unordered_map<T, list<T> > m;
    public:
    graph(bool isDir=false){
        this->isDir = isDir;
    }

    void addedge(T u, T v){
        m[u].push_back(v);
        if(!isDir){
            m[v].push_back(u);
        }
    }
    void print(){
        for(pair<T, list<T> > i : m){
            cout<<i.first<<"->";
            for(T x : i.second){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    graph<string> g(true);
    g.addedge("Avinash", "Saurav");
    g.addedge("Avinash", "Badal");
    g.addedge("Avinash", "Ajaz");
    g.addedge("Saurav", "Prem");
    g.addedge("Prem", "Badal");
    g.addedge("Ajaz", "Badal");

    g.print();
    return 0;
}