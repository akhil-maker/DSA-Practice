#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> graph, int x){
    int s = x, v = graph.size();
    queue<int> q;
    vector<bool> visited(v, false);
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        cout<<s<<" ";
        for(int i=0; i<graph.size(); i++){
            if(!visited[i] && graph[s][i]==1){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    vector<vector<int>> graph = {{0, 1, 1, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}};
    bfs(graph, 2);
}