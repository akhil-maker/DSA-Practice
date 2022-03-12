#include<iostream>
#include<vector>
using namespace std;
void dfsUtil(vector<vector<int>> &graph, vector<bool> &visited, int v){
    visited[v] = true;
    cout<<v<<" ";
    for(int i=0; i<graph.size(); i++)
        if(!visited[i] && graph[v][i]==1)
            dfsUtil(graph, visited, i);
}
void dfs(vector<vector<int>>& graph){
    int v = graph.size();
    vector<bool> visited(v, false);
    for(int i=0; i<v; i++)
        if(!visited[i])
            dfsUtil(graph, visited, i);
}
int main(){
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1}
    };
    dfs(graph);
}