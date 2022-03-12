#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    for(int i=0; i<5; i++){
        cout<<"Adjacency list for vertex "<<i<<":";
        for(auto j:adj[i])
            cout<<j<<"->";
        cout<<endl;
    }
}