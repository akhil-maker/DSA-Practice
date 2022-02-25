#include<iostream>
using namespace std;
int mat[101][101];
int goldmine(int n, int m){
    int dp[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] += mat[j][i];
            if(i>0)
                dp[i][j] += max((j>0)?dp[i-1][j-1]:0, max(dp[i-1][j], (j<n-1)?dp[i-1][j+1]:0));
        }
    }
    int res = 0;
    for(int i=0; i<m; i++)
        res = max(res, dp[i][n-1]);
    return res;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];
    cout<<goldmine(n, m);
}