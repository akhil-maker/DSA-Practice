#include<iostream>
using namespace std;
int rodCutting(int n, int val[]){
    int a[n];
    for(int i=0; i<n; i++)
        a[i] = i+1;
    int dp[n+1][n+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(a[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-a[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][n];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<rodCutting(n, a);
}