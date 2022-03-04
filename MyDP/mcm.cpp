#include<iostream>
using namespace std;
int dp[1001][1001];
int mcm(int a[], int i, int j){
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int tempans, ans = INT_MAX;
    for(int k=i; k<j; k++){
        tempans = mcm(a, i, k)+mcm(a, k+1, j)+a[i-1]*a[k]*a[j];
        ans = min(ans, tempans);
    }
    return dp[i][j] = ans;
}
int main(){
    int a[] = {1, 2, 3, 4, 3};
    for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            dp[i][j] = -1;
    cout<<mcm(a, 1, 4);
}