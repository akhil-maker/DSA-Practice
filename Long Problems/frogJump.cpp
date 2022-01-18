#include<iostream>
using namespace std;
int n, mat[100][100], sx, sy, dx, dy, dis[100][100], visited[100][100];
int addx[] = {1, 0, -1, 0};
int addy[] = {0, 1, 0, -1};
struct queue{
    int x, y;
};
queue q[100];
int f = 0, r = 0;
void init(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dis[i][j] = 0, visited[i][j] = 0;
}
void push(queue temp){
    q[r++] = temp;
}
queue pop(){
    return q[f++];
}
bool isempty(){
    return f==r;
}
bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}
int solve(){
    push({sx, sy});
    visited[sx][sy] = 1;
    dis[sx][sy] = 0;
    while(!isempty()){
        queue t = pop();
        int p = t.x, q = t.y;
        for(int i=0; i<4; i++){
            int nx = p+addx[i];
            int ny = q+addy[i];
            if(valid(nx, ny) && visited[nx][ny]==0 && mat[nx][ny]==1){
                if(i==0 || i==2)
                    dis[nx][ny] = 1+dis[p][q];
                else if(i==1 || i==3)
                    dis[nx][ny] = dis[p][q];
                visited[nx][ny] = 1;
                push({nx, ny});
            }
            cout<<nx<<" "<<ny<<" "<<((visited[nx][ny]==1)?(visited[nx][ny]):-1)<<" "<<dis[nx][ny]<<endl;
        }
    }
    return dis[dx][dy];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        cin>>sx>>sy>>dx>>dy;
        init();
        cout<<solve();
    }
}