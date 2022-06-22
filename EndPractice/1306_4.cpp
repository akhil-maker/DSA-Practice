//4
#include<iostream>
using namespace std;
int frog(int n, int k, int h[]){
    int dp[n];
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int mx = 1e8;
        for(int j=1; j<=k; j++)
            if(i-j >= 0)
                mx = min(mx, dp[i-j]+abs(h[i]-h[i-j]));
        dp[i] = mx;
    }
    return dp[n-1];
}
int main(){
    int n, k;
    cin>>n>>k;
    int h[n];
    for(int i=0; i<n; i++)
        cin>>h[i];
    cout<<frog(n, k, h);
}