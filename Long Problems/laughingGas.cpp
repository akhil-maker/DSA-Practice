#include<iostream>
using namespace std;
int m, n, a[100][100], visited[100][100], ans = INT_MAX;
int addx[] = {1, 0, -1, 0};
int addy[] = {0, 1, 0, -1};
struct point{
    int x, y, l;
};
struct queue{
    point w;
};
queue q[100];
int f = 0, r = 0;
void push(queue b){
    q[r++] = b;
}
queue pop(){
    return q[f++];
}
void init(){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = INT_MAX;
}
bool isempty(){
    return f==r;
}
int bfs(){
    int s = 0;
    queue temp;
    point p, p1, p2;
    int t, u, v;
    p.x = 0, p.y = 0, p.l = 1;
    temp.w = p;
    push(temp);
    a[p.x][p.y] = 2;
    while(!isempty()){
        temp = pop();
        p1 = temp.w;
        for(int k=0; k<4; k++){
            u = p1.x + addx[k];
            v = p1.y + addy[k];
            t = p1.l + 1;
            if(a[u][v]==1){
                p2.x = u;
                p2.y = v;
                p2.l = t;
                a[p2.x][p2.y] = 2;
                queue c;
                c.w = p2;
                push(c);
            }
        }
    }
    return t-1;
}
int main(){
    cin>>m>>n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    init();
    cout<<bfs();
}