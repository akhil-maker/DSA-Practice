#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src, dest, weight;
};
bool negCycle(int v, vector<Edge> w, int src){
    int dist[v];
    for(int i=0; i<v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for(int i=1; i<=v-1; i++){
        for(int j=0; j<w.size(); j++){
            int u = w[j].src;
            int v = w[j].dest;
            int wt = w[j].weight;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)
                dist[v] = dist[u] + wt;
        }
    }
    for(int i=0; i<w.size(); i++){
        int u = w[i].src;
        int v = w[i].dest;
        int wt = w[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
            return true;
    }
    return false;
}
int main(){
    vector<Edge> w = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 0, -1}
    };
    cout<<negCycle(4, w, 0);
}