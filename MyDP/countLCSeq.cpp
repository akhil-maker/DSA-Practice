#include<iostream>
using namespace std;
int lcs(string x, string y, int m, int n){
    if(n==0 || m==0)
        return 0;
    if(x[m-1]==y[n-1])
        return 1+lcs(x, y, m-1, n-1);
    return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
}
int dplcs(string x, string y){
    int m = x.length(), n = y.length();
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    string x, y;
    cin>>x>>y;
    cout<<dplcs(x, y)<<endl<<lcs(x, y, x.length(), y.length());
}