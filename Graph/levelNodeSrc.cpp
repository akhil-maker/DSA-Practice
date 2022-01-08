#include<bits/stdc++.h>
using namespace std;
vector<int> srcLevel(vector<vector<int>> &a){
    vector<int> visited(a.size(), 0);
    vector<int> level(a.size(), 0);
    queue<int> q;
    int v = 0;
    level[v] = 0;
    visited[v] = 1;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int j=0; j<a.size(); j++){
            if(a[v][j]==1 && visited[j]==0){
                q.push(j);
                visited[j] = 1;
                level[j] = level[v] + 1;
            }
        }
    }
    return level;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0}
    };
    vector<int> r = srcLevel(a);
    for(int i=0; i<r.size(); i++)
        cout<<i<<" "<<r[i]<<endl;
}