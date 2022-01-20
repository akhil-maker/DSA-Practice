#include<iostream>
using namespace std;
int n, mat[100][100], visited[100][100], res[100][100], ans;
int addx[] = {1, 0, -1, 0};
int addy[] = {0, 1, 0, -1};
void init(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0, res[i][j] = 0;
}
bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}
void solve(int x, int y, int total){
    if(x==n-1 && y==n-1){
        if(total>=ans){
            ans = total;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(visited[i][j])
                        res[i][j] = 3;
                    else
                        res[i][j] = mat[i][j];
                }
            }
        }
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + addx[i];
        int ny = y + addy[i];
        if(valid(nx, ny)){
            if(visited[nx][ny]==0 && mat[nx][ny]==0){
                visited[nx][ny] = 1;
                solve(nx, ny, total);
                visited[nx][ny] = 0;
            }
            if(visited[nx][ny]==0 && mat[nx][ny]==2){
                visited[nx][ny] = 1;
                solve(nx, ny, total+1);
                visited[nx][ny] = 0;
            }
        }
    }
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
        visited[0][0] = 1;
        if(mat[0][0]==2)
            solve(0, 0, 1);
        else
            solve(0, 0, 0);
        cout<<ans<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<res[i][j];
            cout<<endl;
        }
    }
}