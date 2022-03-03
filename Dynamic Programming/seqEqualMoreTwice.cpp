#include<iostream>
using namespace std;
int getNumofSeq(int m, int n){
    if(m<n)
        return 0;
    if(n==0)
        return 1;
    return getNumofSeq(m-1, n)+getNumofSeq(m/2, n-1);
}
int getNumofSeqdp(int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 1;
            else if(i<j)
                dp[i][j] = 0;
            else if(j==1)
                dp[i][j] = i;
            else    
                dp[i][j] = dp[i-1][j]+dp[i/2][j-1];
        }
    }
    return dp[m][n];
}
int main(){
    cout<<getNumofSeq(10, 4)<<endl<<getNumofSeqdp(10, 4);
}