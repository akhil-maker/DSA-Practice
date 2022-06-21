//11
#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>>& a, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        dp[n-1][i] = a[n-1][i];
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int b = a[i][j] + dp[i+1][j];
            int dl = a[i][j] + dp[i+1][j+1];
            dp[i][j] = max(b, dl);
        }
    }
    return dp[0][0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            cin>>a[i][j];
    cout<<f(a, n);
}