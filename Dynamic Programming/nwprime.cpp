#include<iostream>
using namespace std;
int nwPrime(int n){
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++)
        dp[i] = 2*dp[i-1]+dp[i-2];
    return dp[n];
}
int main(){
    cout<<nwPrime(4);
}