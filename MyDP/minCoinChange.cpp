#include<iostream>
using namespace std;
int minCoin(int coins[], int n, int amt){
    int dp[n+1][amt+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<amt+1; j++)
            dp[i][0] = 0, dp[0][j] = INT_MAX-1;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<amt+1; j++){
            if(coins[i-1]<=j)
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amt];
}
//Lower space complexity
int minCoinsOpt(int coins[], int n, int amt){
    int dp[amt+1];
    dp[0] = 0;
    for(int i=1; i<=amt; i++)
        dp[i] = INT_MAX;
    for(int i=1; i<=amt; i++){
        for(int j=0; j<n; j++){
            if(coins[j]<=i){
                int subres = dp[i-coins[j]];
                if(subres!=INT_MAX && subres+1<dp[i])
                    dp[i] = subres+1;
            }
        }
    }
    if(dp[amt]==INT_MAX)
        return -1;
    return dp[amt];
}
int main(){
    int coins[] = {1, 3, 5, 7};
    cout<<minCoin(coins, 4, 18);
}