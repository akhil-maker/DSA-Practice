#include<bits/stdc++.h>
using namespace std;
void DFSUtil(vector<vector<int>> &a, int i, vector<int> &visited){
    visited[i] = 1;
    for(int j=0; j<a.size(); j++)
        if(visited[j]==0 && a[i][j]==1)
            DFSUtil(a, j, visited);
}
vector<vector<int>> dfs(vector<vector<int>> &a){
    vector<vector<int>> res;
    for(int i=0; i<a.size(); i++){
        vector<int> visited(a.size(), 0);
        DFSUtil(a, i, visited);
        res.push_back(visited);
    }
    return res;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
    };
    vector<vector<int>> r = dfs(a);
    cout<<"Transitive closure matrix is"<<endl;
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}