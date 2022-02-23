#include<iostream>
using namespace std;
int targetSum(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    bool dp[n+1][sum+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
            dp[0][j] = false, dp[i][0] = true;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(a[i-1]<=j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    } 
    int mn = INT_MAX;
    for(int i=0; i<sum+1; i++)
        if(dp[n][i]==true && (sum-2*i)>=0)
            mn = min(mn, (sum-2*i));
    return mn;
}
int main(){
    int a[] = {9, 1, 2, 3};
    cout<<targetSum(a, 4);
}