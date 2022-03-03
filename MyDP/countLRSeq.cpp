#include<iostream>
using namespace std;
int LRS(string x){
    string y = x;
    int m = x.length(), n = y.length();
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(i!=j && x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    string x;
    cin>>x;
    cout<<LRS(x);
}