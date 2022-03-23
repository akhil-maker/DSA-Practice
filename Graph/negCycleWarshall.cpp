#include<iostream>
#include<vector>
#define INF 99999
using namespace std;
bool negCycleWarshall(vector<vector<int>> graph){
    vector<vector<int>> dist;
    for(int i=0; i<graph.size(); i++){
        vector<int> v(graph[i]);
        dist.push_back(v);
    }
    int V = graph.size();
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(int i=0; i<V; i++)
        if(dist[i][i]<0)
            return true;
    return false;
}
int main(){
    vector<vector<int>> g = {
        {0, 1, INF, INF},
        {INF, 0, -1, INF},
        {INF, INF, 0, -1},
        {-1, INF, INF, 0}
    };
    if(negCycleWarshall(g))
        cout<<"Yes";
    else
        cout<<"No";
}