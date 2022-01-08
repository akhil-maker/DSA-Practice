#include<bits/stdc++.h>
using namespace std;
void counter(int src, int dest, vector<vector<int>> &a, vector<int> &visited, int &cnt){
    visited[src] = 1;
    if(src==dest)
        cnt += 1;
    else{
        for(int j=0; j<a.size(); j++)
            if(a[src][j]==1 && visited[j]==0)
                counter(j, dest, a, visited, cnt);
    }
    visited[src] = 0;
}
int cntPath(int src, int dest, vector<vector<int>> &a){
    int cnt = 0;
    vector<int> visited(a.size(), 0);
    counter(src, dest, a, visited, cnt);
    return cnt;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    cout<<cntPath(0, 4, a);
}