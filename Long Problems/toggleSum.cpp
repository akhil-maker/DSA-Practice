#include<iostream>
using namespace std;
int grid[1001][1001];
int rowone(int n, int m){
    int cnt = 0;
    for(int i=0; i<n; i++){
        int k = 0;
        for(int j=0; j<m; j++)
            if(grid[i][j]==1)
                k++;
        if(k==m)
            cnt++;
    }
    return cnt;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    int s = rowone(n, m);
    
}