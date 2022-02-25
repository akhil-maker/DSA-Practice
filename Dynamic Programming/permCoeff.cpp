#include<iostream>
using namespace std;
int permCoeff(int n, int k){
    int dp[n+1][k+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<=min(i, k); j++){
            if(j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j]+j*dp[i-1][j-1];
            dp[i][j+1] = 0;
        }
    }
    return dp[n][k];
}
int main(){
    cout<<permCoeff(10, 2);
}