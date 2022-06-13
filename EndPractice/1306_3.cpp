//3, 4, 6, 7, 11
#include<iostream>
using namespace std;
int f(int i, int h[], int dp[]){
    if(i==0) return 0;
    if(i<0) return 1e8;
    if(dp[i]!=-1) return dp[i];
    int c1 = f(i-1, h, dp) + abs(h[i]-h[i-1]);
    int c2 = 1e8;
    if(i>1)
        c2 = f(i-2, h, dp) + abs(h[i]-h[i-2]);
    return dp[i] = min(c1, c2);
}
int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0; i<n; i++)
        cin>>h[i];
    int dp[n];
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int x = dp[i-1] + abs(h[i]-h[i-1]);
        int y = 1e8;
        if(i>1)
            y = dp[i-2] + abs(h[i]-h[i-2]);
        dp[i] = min(x, y);
    }
    cout<<dp[n-1];
}