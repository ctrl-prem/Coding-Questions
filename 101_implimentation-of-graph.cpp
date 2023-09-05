// Implimentation using list: Adjacency list
// Here, Vertices are represented by the index of the array and the edges between them are reprensented by the list. 

#include<iostream>
#include<list>
using namespace std;


class graph{
    int v;
    bool isDirected;
    int val;
    list<int> *arr;
    public:
    graph(int v, bool isDirected = false){
        this->v = v;
        this->isDirected = isDirected;
        arr = new list<int>[v];
    }
    void addedge(int v, int val){
        arr[v].push_back(val);
        if(!isDirected){
            arr[val].push_back(v);
        }
    }

    void print(){
        for(int i=0; i<v; i++){
            cout<<i<<"->";
            list<int> neigbourlist = arr[i];
            for(int neighbour: neigbourlist){
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    graph g(5);
    g.addedge(0, 1);
    g.addedge(0, 4);
    g.addedge(0, 3);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);

    g.print();
    return 0;
}
