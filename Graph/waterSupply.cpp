#include<iostream>
#include<vector>
#include<queue>
using namespace std;    
int bfsUtil(vector<vector<int>>& a, vector<int>& allow, vector<bool>& visited, int v){
    visited[v] = true;
    queue<int> q;
    q.push(v);
    int cnt = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<a.size(); i++){
            if(a[x][i]==1 && !visited[i] && allow[i]==0){
                visited[i] = true;
                q.push(i);
                cnt++;
            }
            else if(a[x][i]==1 && !visited[i] && allow[i]==1)
                cnt++;
        }
    }
    return cnt;
}
int countWaterPlace(vector<vector<int>>& a, vector<int>& allow){
    vector<bool> visited(a.size(), false);
    int res = 1;
    for(int i=0; i<a.size(); i++){
        if(allow[i]==0 && !visited[i]){
            int cnt = bfsUtil(a, allow, visited, i);
            res = max(cnt, res);
        }
    }
    return res;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
    };
    vector<int> allow = {0, 1, 1, 0, 0, 0, 0};
    cout<<countWaterPlace(a, allow);
}