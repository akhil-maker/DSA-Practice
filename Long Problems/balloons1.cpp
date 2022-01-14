#include<iostream>
using namespace std;
int burstBalloon(int a[], int n){
    int b[n+2];
    b[0] = b[n+1] = 1;
    for(int i=1; i<=n; i++)
        b[i] = a[i-1];
    int dp[n+2][n+2];
    for(int i=0; i<n+2; i++)
        for(int j=0; j<n+2; j++)
            dp[i][j] = 0;
    for(int L=1; L<n+1; L++){
        for(int i=1; i<n-L+2; i++){
            int j = i+L-1;
            for(int k=i; k<=j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k-1]+((i==1 && j==n)?b[k]:(b[i-1]*b[j+1]))+dp[k+1][j]);
        }
    }
    return dp[1][n];
}
int main(){
    int a[] = {1, 2, 3, 4};
    cout<<burstBalloon(a, 4);
}