#include<iostream>
using namespace std;
int LRStr(string x){
    string y = x;
    int m = x.length(), n = y.length(), r = 0;
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(i!=j && x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = 0;
            r = max(r, dp[i][j]);
        }
    }
    return r;
}
int main(){
    string x;
    cin>>x;
    cout<<LRStr(x);
}