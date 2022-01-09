#include<bits/stdc++.h>
using namespace std;
void printSol(vector<int> &dist){
    cout<<"Vertices  Distance from source"<<endl;
    for(int i=0; i<dist.size(); i++)
        cout<<i<<" \t\t"<<dist[i]<<endl;
}
int minDist(vector<int> &dist, vector<int> &visited){
    int mn = INT_MAX, mndex;
    for(int v=0; v<dist.size(); v++)
        if(visited[v]==0 && dist[v]<=mn)
            mn = dist[v], mndex = v;
    return mndex;
}
void shortPath(vector<vector<int>> &a, int src){
    int n = a.size();
    vector<int> visited(n, 0);
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for(int i=0; i<n; i++){
        int u = minDist(dist, visited);
        visited[u] = 1;
        for(int v=0; v<n; v++)
            if(visited[v]==0 && a[u][v] && dist[u]!=INT_MAX && dist[u]+a[u][v]<dist[v])
                dist[v] = dist[u] + a[u][v];
    }
    printSol(dist);
}
int main(){
    vector<vector<int>> a = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    shortPath(a, 0);
}