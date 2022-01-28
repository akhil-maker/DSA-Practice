#include<iostream>
using namespace std;
struct Point{
    int x, y;
};
struct Cr{
    int x, y, dis;
};
struct queue{
    Cr r;
};
Cr q[100];
int f = 0, r = 0;
void push(Cr x){
    q[r++] = x;
}
Cr pop(){
    return q[f++];
}
bool isEmpty(){
    return f==r;
}
int a[21][21];
int ans[21][21], n;
bool visited[21][21];
int addx[] = {0, 1, 0, -1};
int addy[] = {1, 0, -1, 0};
bool isSafe(int x, int y){
    return (x>=0 && y>=0 && x<n && y<n && a[x][y]);
}
void bfs(int x, int y){
   Cr in;
   in.x = x;
   in.y = y;
   in.dis = 0;
   push(in);
   visited[x][y] = 1;
   while(!isEmpty()){
       Cr c = pop();
       int a = c.x;
       int b = c.y;
       int dis = c.dis;
       ans[a][b] = dis;
       for(int i=0; i<4; i++){
           int nx = a+addx[i];
           int ny = b+addy[i];
           if(isSafe(nx, ny) && visited[nx][ny]==0){
               visited[nx][nx] = 1;
               in.x = nx;
               in.y = ny;
               in.dis = dis+1;
               push(in);
           }
       }
   }
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    int q;
    cin>>q;
    Point rare[q];
    int fans = 10000;
    int mx = -1;
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        rare[i].x = a;
        rare[i].y = b;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int u=0; u<21; u++)
                for(int v=0; v<21; v++)
                    ans[u][v] = 10000;
            int flag = 0;
            for(int u=0; u<21; u++)
                for(int v=0; v<21; v++)
                    visited[u][v] = 0;
            mx = -1;
            if(a[i][j]){
                bfs(i, j);
                for(int k=0; k<q; k++)
                    mx = max(mx, ans[rare[k].x][rare[k].y]);
                fans = min(fans, mx);
                cout<<fans<<endl;
            }
        }
    }
    cout<<fans-1<<endl;
}