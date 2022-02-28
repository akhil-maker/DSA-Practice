#include<iostream>
using namespace std;
int maxWeightage(int wt[], int n, int val[], int W){
    int dp[n+1][W+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(j>=wt[i-1])
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main(){
    int n;
    cin>>n;
    string s[n];
    int wt[n];
    int val[n];
    for(int i=0; i<n; i++){
        cin>>s[i]>>val[i];
        wt[i] = s[i].length()+1;
    }
    int W;
    cin>>W;
    cout<<maxWeightage(wt, n, val, W);
}