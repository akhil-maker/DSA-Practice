#include<iostream>
using namespace std;
int maxCost(int w[], int c[], int n, int k){
    int dp[n+1][k+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<k+1; j++)
            if(i==0 || j==0)
                dp[i][j] = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<k+1; j++){
            if(j-w[i-1]>=0)
                dp[i][j] = max(dp[i-1][j-w[i-1]]+c[i-1], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}
int main(){
    int n = 6, k = 20;
    int w[] = {9, 7, 6, 5, 8, 4};
    int c[] = {7, 1, 3, 6, 8, 3};
    cout<<maxCost(w, c, n, k);
}