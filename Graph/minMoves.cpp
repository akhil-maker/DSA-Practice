#include<iostream>
#include<vector>
using namespace std;
int dfs(vector<vector<int>>& m, int x, int y, vector<vector<bool>>& visited, int ans){
    int addx[] = {1, -1, 0, 0}, addy[] = {0, 0, -1, 1};
    cout<<x<<" "<<y<<endl;
    if(m[x][y]==2){
        cout<<"ans = "<<ans<<endl;
        return ans;
    }
    int res = INT_MAX;
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int px = x+addx[i], py = y+addy[i];
        if(px>=0 && py>=0 && px<m.size() && py<m[0].size() && (m[px][py]==3 || m[px][py]==2) && !visited[px][py]){
            int cnt = dfs(m, px, py, visited, ans+1);
            res = min(cnt, res);
        }
    }
    cout<<endl;
    visited[x][y] = false;
    return res;
}
int minMoves(vector<vector<int>>& m){
    int cnt = 0, ans = INT_MAX;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[0].size(); j++){
            if(m[i][j]==1){
                vector<vector<bool>> visited;
                for(int k=0; k<m.size(); k++){
                    vector<bool> v(m[0].size(), false);
                    visited.push_back(v);
                }
                cnt = dfs(m, i, j, visited, 0);
                break;
            }
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>> m = {
        {3, 3, 1, 0},
        {3, 0, 3, 3},
        {2, 3, 0, 3},
        {0, 3, 3, 3}
    };
    cout<<minMoves(m);
}