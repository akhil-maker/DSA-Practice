#include<iostream>
using namespace std;
void lcs(string x, string y){
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
    int i = m, j = n;
    string r = "";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            r = x[i-1]+r;
            i--, j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<r;
}
int main(){
    string x, y;
    cin>>x>>y;
    lcs(x, y);
}