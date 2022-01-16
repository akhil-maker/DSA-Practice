#include<iostream>
using namespace std;
int row, col, x, y, l;
int map[1000][1000], visited[1000][1000];
struct queue{
    int x, y, l;
};
queue q[100000];
int front, back;
void init(){
    front = 0;
    back = 0;
}
void push(queue temp){
    q[back++] = temp;
}
queue pop(){
    return q[front++];
}
bool empty(){
    return front==back;
}
bool valid(int x, int y){
    return (x<row && x>=0 && y<col && y>=0);
}
bool left(int x, int y){
    return (map[x][y]==1 || map[x][y]==3 || map[x][y]==6 || map[x][y]==7);
}
bool right(int x, int y){
    return (map[x][y]==1 || map[x][y]==3 || map[x][y]==4 || map[x][y]==5);
}bool up(int x, int y){
    return (map[x][y]==1 || map[x][y]==2 || map[x][y]==4 || map[x][y]==7);
}bool down(int x, int y){
    return (map[x][y]==1 || map[x][y]==2 || map[x][y]==5 || map[x][y]==6);
}
int solve(int x, int y, int l){
    int ans = 0;
    push({x, y, l});
    visited[x][y] = true;
    while(empty()!=true){
        queue curr = pop();
        int x = curr.x, y = curr.y, l = curr.l;
        if(l==0) continue;
        ans++;
        if(valid(x, y-1) && visited[x][y-1]==0 && left(x, y) && right(x, y-1)){
            push({x, y-1, l-1});
            visited[x][y-1] = true;
        }
        if(valid(x, y+1) && visited[x][y+1]==0 && right(x, y) && left(x, y+1)){ 
            push({x, y+1, l-1});
            visited[x][y+1] = true;
        }
        if(valid(x-1, y) && visited[x-1][y]==0 && up(x, y) && down(x-1, y)){
            push({x-1, y, l-1});
            visited[x-1][y] = true;
        }
        if(valid(x+1, y) && visited[x+1][y]==0 && up(x+1, y) && down(x+1, y)){
            push({x+1, y, l-1});
            visited[x+1][y] = true;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>row>>col>>x>>y>>l;
        init();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>map[i][j];
                visited[i][j] = 0;
            }
        }
        if(map[x][y]>0)
            cout<<solve(x, y, l)<<endl;
        else
            cout<<0<<endl;
    }
}