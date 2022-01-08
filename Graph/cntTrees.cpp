#include<bits/stdc++.h>
using namespace std;
void DFSUtil(vector<vector<int>> &a, int i, vector<int> &visited){
    visited[i] = 1;
    for(int j=0; j<a.size(); j++)
        if(a[i][j]==1 && visited[j]==0)
            DFSUtil(a, j, visited);
}
int dfs(vector<vector<int>> &a){
    int cnt = 0;
    vector<int> visited(a.size(), 0);
    for(int i=0; i<a.size(); i++){
        if(visited[i]==0){
            cnt++;
            DFSUtil(a, i, visited);
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    cout<<dfs(a);
}