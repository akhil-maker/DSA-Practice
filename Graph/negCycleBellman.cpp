#include<iostream>
#include<vector>
using namespace std;
struct Edge{
    int src, dest, weight;
};
struct Graph{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E){
    Graph* g = new Graph;
    g->V = V;
    g->E = E;
    g->edge = new Edge[g->E];
    return g;
}
bool isNegCycle(Graph* g, int src){
    int V = g->V;
    int E = g->E;
    int dist[V];
    for(int i=0; i<V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for(int i=1; i<=V-1; i++){
        for(int j=0; j<E; j++){
            int u = g->edge[j].src;
            int v = g->edge[j].dest;
            int wt = g->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
                dist[v] = dist[u]+wt;
        }
    }
    for(int i=0; i<E; i++){
        int u = g->edge[i].src;
        int v = g->edge[i].dest;
        int wt = g->edge[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
            return true;
    }
    return false;
}
int main(){
    int V = 5;
    int E = 8;
    Graph* g = createGraph(V, E);

    g->edge[0].src = 0;
    g->edge[0].dest = 1;
    g->edge[0].weight = -1;

    g->edge[1].src = 0;
    g->edge[1].dest = 2;
    g->edge[1].weight = 4;

    g->edge[2].src = 1;
    g->edge[2].dest = 2;
    g->edge[2].weight = 3;

    g->edge[3].src = 1;
    g->edge[3].dest = 3;
    g->edge[3].weight = 2;

    g->edge[4].src = 1;
    g->edge[4].dest = 4;
    g->edge[4].weight = 2;

    g->edge[5].src = 3;
    g->edge[5].dest = 2;
    g->edge[5].weight = 5;

    g->edge[6].src = 3;
    g->edge[6].dest = 1;
    g->edge[6].weight = 1;

    g->edge[7].src = 4;
    g->edge[7].dest = 3;
    g->edge[7].weight = -3;

    if(isNegCycle(g, 0))
        cout<<"Yes";
    else
        cout<<"No";
}