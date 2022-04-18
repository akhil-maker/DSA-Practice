#include<bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>>& a, int n, int m, int k){
    if(a[0][0]==1 && k==0)
        return -1;
    if(a[n-1][m-1]==1 && k==0)
        return -1;
    queue<vector<int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({0, 0, 0});
    int r, c, path = 0;
    while(!q.empty()){
        r = q.front()[0];
        c = q.front()[1];
        path = q.front()[2];
        q.pop();
        if(r>=0 && c>=0 && r<n && c<m){
            if(r==n-1 && c==m-1){
                if(a[r][c]==0)
                    return path;
                else
                    return -1;
            }
            if(a[r][c]==1 && visited[r][c]==0){
                if(k>0){
                    a[r][c] = 0;
                    k--;
                }
                else    
                    continue;
            }
            a[r][c] = 1;
            visited[r][c] = 1;
            q.push({r+1, c, path+1});
            q.push({r-1, c, path+1});
            q.push({r, c+1, path+1});
            q.push({r, c-1, path+1});
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> a = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}};
    cout<<shortestPath(a, 3, 3, 1);
}