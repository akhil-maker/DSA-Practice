#include<iostream>
#include<queue>
using namespace std;
struct cell{
    int x, y, dis;
    cell(){}
    cell(int x, int y, int dis):x(x), y(y), dis(dis){
    }
};
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool isInside(int x, int y, int n){
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}
int bfs(int knight[], int target[], int n){
    queue<cell> q;
    bool visited[n+1][n+1];
    cell t;
    int x, y, l;
    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            visited[i][j] = false;
    q.push(cell(knight[0], knight[1], 0));
    visited[knight[0]][knight[1]] = true;
    while(!q.empty()){
        t = q.front();
        q.pop();
        for(int j=0; j<8; j++){
            x = t.x + dx[j];
            y = t.y + dy[j];
            if(!visited[x][y] && isInside(x, y, n)){
                q.push(cell(x, y, t.dis+1));
                visited[x][y] = true;
            }
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int knight[2], target[2];
    cin>>knight[0]>>knight[1]>>target[0]>>target[1];
    cout<<bfs(knight, target, n);
}