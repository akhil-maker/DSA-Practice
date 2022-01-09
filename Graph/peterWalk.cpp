#include<bits/stdc++.h>
using namespace std;
int DFSUtil(int v, string s, vector<vector<int>> &a, vector<int> visited){
    if(v==s.length()-1)
        return 1;
    visited[s[v]-'0'] = 1;
    int x = -1;
    if(visited[s[v+1]-'0']==0 && a[s[v]-'0'][s[v+1]-'0']==1)
        x = DFSUtil(v+1, s, a, visited);
    return x;
}
bool dfs(string s, vector<vector<int>> &a){
    vector<int> visited(a.size(), 0);
    int v = 0;
    int res = DFSUtil(v, s, a, visited);
    if(res==1)
        return true;
    return false;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 1, 0, 0}
    };
    cout<<dfs("566", a);
}