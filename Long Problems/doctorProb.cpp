#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<float>> prob;
vector<vector<int>> graph;
int bfs(int n, int k){
    int s = 0;
    int visited[n] = {0};
    for(int i=0; i<n; i++){
        if(k<10)
            return s+1;
        int r = s;
        visited[s] = 1;
        for(int j=0; j<n; j++){
            if(visited[j]==0 && graph[s][j]==1 && prob[s][j]>prob[s][r] && j!=s)
                r = j;
        }
        if(r!=s)
            s = r;
        k -= 10;
    }
    if(k>=0)
        return -1;
    return s+1;
}
int main(){
    graph = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1}
    };
    prob = {
        {0, 0.3, 0.7, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0.2, 0.8, 0, 0},
        {0, 0, 0, 0.1, 0.9, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0.5, 0, 0, 0.5}
    };
    cout<<bfs(6, 60);
}