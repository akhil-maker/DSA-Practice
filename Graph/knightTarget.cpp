#include<iostream>
#include<queue>
using namespace std;
struct cell{
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis): x(x), y(y), dis(dis){}
};
bool isSafe(int x, int y, int n){
    if(x>=1 && x<=n && y>=1 && y<=n)
        return true;
    return false;
}
int knightTarget(int kpos[], int tpos[], int n){
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -2, 1, 2, 2, 1};
    queue<cell> q;
    q.push(cell(kpos[0], kpos[1], 0));
    cell t;
    int x, y;
    bool visited[n+1][n+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            visited[i][j] = false;
    visited[kpos[0]][kpos[1]] = true;
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(t.x==tpos[0] && t.y==tpos[1])
            return t.dis;
        for(int i=0; i<8; i++){
            x = t.x+dx[i];
            y = t.y+dy[i];
            if(isSafe(x, y, n) && !visited[x][y]){
                visited[x][y] = true;
                q.push(cell(x, y, t.dis+1));
            }
        }
    }
    return -1;
}
int main(){
    int n = 30;
    int kpos[] = {1, 1};
    int tpos[] = {30, 30};
    cout<<knightTarget(kpos, tpos, n);
}