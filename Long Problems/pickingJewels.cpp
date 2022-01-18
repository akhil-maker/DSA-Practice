#include<iostream>
using namespace std;
int n, mat[100][100], visited[100][100], res[100][100], mxJewels = 0;
int addx[] = {1, 0, -1, 0};
int addy[] = {0, 1, 0, -1};
struct queue{
    int x, y;
};
queue q[100];
int f = 0, r = 0;
void push(queue x){
    q[r++] = x;
}
queue pop(){
    return q[f++];
}
bool empty(){
    return f==r;
}
void init(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0, res[i][j] = 0;
}
bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}
int solve(int i, int j, int total){
    int ret = 0;
    res[i][j] = 3;
    visited[i][j] = 1;
    if(i==0 && j==0 && mat[i][j]==2)
        total++;
    if(i==n-1 && j==n-1){
        if(total>mxJewels)
            mxJewels = total;
        visited[i][j] = 0;
        return 1;
    }
    if((j+1)<=n-1){ //down
        if(visited[i][j+1]==0 && mat[i][j+1]!=1){
            if(mat[i][j+1]==2)
                solve(i, j+1, total+1);
            else
                solve(i, j+1, total);
            res[i][j+1] = mat[i][j+1];
        }
    }
    if((j-1)>=0){ //up
        if(visited[i][j-1]==0 && mat[i][j-1]!=1){
            if(mat[i][j-1]==2)
                solve(i, j-1, total+1);
            else
                solve(i, j-1, total);
            res[i][j-1] = mat[i][j-1];
        }
    }
    if((i+1)<=n-1){ //right
        if(visited[i+1][j]==0 && mat[i+1][j]!=1){
            if(mat[i+1][j]==2)
                solve(i+1, j, total+1);
            else
                solve(i+1, j, total);
            res[i+1][j] = mat[i+1][j];
        }
    }
    if((i-1)>=0){ //left
        if(visited[i-1][j]==0 && mat[i-1][j]!=1){
            if(mat[i-1][j]==2)
                solve(i-1, j, total+1);
            else
                solve(i-1, j, total);
            res[i-1][j] = mat[i-1][j];
        }
    }
    visited[i][j] = 0;
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        init();
        cout<<solve(0, 0, 0)<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<mat[i][j];
            cout<<endl;
        }
    }
}