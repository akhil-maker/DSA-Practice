#include<iostream>
using namespace std;
int maxProfit(int n, int price[], int l){
    int len[l+1];
    for(int i=1; i<=l; i++)
        len[i-1] = i;
    int dp[n+1][l+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<l+1; j++)
            dp[0][j] = 0, dp[i][0] = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<l+1; j++){
            if(len[i-1]<=j)
                dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][l];
}
int main(){
    int n = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 19, 20};
    cout<<maxProfit(n, price, 12);
}