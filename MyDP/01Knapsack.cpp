#include<iostream>
using namespace std;
int knapsack(int wt[], int val[], int n, int W){
    int dp[n+1][W+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(wt[i-1]<=j)
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main(){
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    cout<<knapsack(wt, val, 4, 7);
}