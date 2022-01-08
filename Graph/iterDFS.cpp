#include<bits/stdc++.h>
using namespace std;
void DFSUtil(vector<vector<int>> &a, vector<int> &visited, int i){
    stack<int> s;
    s.push(i);
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(visited[v]==0){
            cout<<v<<" ";
            visited[v] = 1;
        }
        for(int j=0; j<a.size(); j++)
            if(visited[j]==0 && a[v][j]==1)
                s.push(j);
    }
}
void DFS(vector<vector<int>> &a){
    vector<int> visited(a.size(), 0);
    for(int i=0; i<a.size(); i++)
        if(visited[i]==0)
            DFSUtil(a, visited, i);
}
int main(){
    vector<vector<int>> a = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0}
    };
    DFS(a);
}