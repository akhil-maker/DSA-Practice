#include<bits/stdc++.h>
using namespace std;
int cntNodesLev(vector<vector<int>> &a, int l){
    vector<int> visited(a.size(), 0);
    queue<int> q;
    vector<int> level(a.size(), 0);
    int s = 0;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(int j=0; j<a.size(); j++){
            if(a[s][j]==1 && visited[j]==0){
                q.push(j);
                visited[j] = 1;
                level[j] = level[s]+1;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<a.size(); i++)
        if(level[i]==l)
            cnt++;
    return cnt;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
    };
    cout<<cntNodesLev(a, 2);
}