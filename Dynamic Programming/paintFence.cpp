#include<iostream>
using namespace std;
int paintFence(int n, int k){
    int dp[n+1] = {0};
    dp[1] = k, dp[2] = k*k;
    for(int i=3; i<=n; i++)
        dp[i] = (dp[i-1]+dp[i-2])*(k-1);
    return dp[n];
}
int main(){
    cout<<paintFence(3, 2);
}