#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> adj[n];
    for(int i=0; i<m; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);
    vector<int> key(n, INT_MAX);
    key[0] = 0;
    parent[0]= -1;
    for(int i=0; i<n-1; i++){
        int mini = INT_MAX, u;
        for(int v=0; v<n; v++)
            if(mst[v]==false && key[v]<mini)
                mini = key[v], u = v;
        mst[u] = true;
        for(auto it:adj[u]){
            int v = it.first;
            int wt = it.second;
            if(mst[v]==false && wt<key[v])
                parent[v] = u, key[v] = wt;
        }
    }
    for(int i=1; i<n; i++)
        cout<<parent[i]<<"--->"<<i<<endl;
}