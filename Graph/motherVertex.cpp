#include<bits/stdc++.h>
using namespace std;
void DFSUtil(vector<vector<int>> &a, int i, vector<int> &visited){
    visited[i] = 1;
    for(int j=0; j<a.size(); j++)
        if(a[i][j]==1 && visited[j]==0)
            DFSUtil(a, j, visited);
}
int findMother(vector<vector<int>> &a){
    vector<int> visited(a.size(), 0);
    int v = 0;
    for(int i=0; i<a.size(); i++){
        if(visited[i]==0){
            DFSUtil(a, i, visited);
            v = i;
        }
    }
    fill(visited.begin(), visited.end(), 0);
    DFSUtil(a, v, visited);
    for(int i=0; i<a.size(); i++)
        if(visited[i]==0)
            return -1;
    return v;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0}
    };
    cout<<findMother(a);
}