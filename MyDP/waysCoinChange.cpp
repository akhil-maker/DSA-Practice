#include<iostream>
using namespace std;
int maxWays(int coins[], int n, int amt){
    int dp[n+1][amt+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<amt+1; j++)
            dp[0][j] = 0, dp[i][0] = 1;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<amt+1; j++){
            if(coins[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amt];
}
int main(){
    int coins[] = {1, 2, 3};
    cout<<maxWays(coins, 3, 5);
}