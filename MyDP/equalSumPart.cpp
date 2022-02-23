#include<iostream>
using namespace std;
bool isSubsum(int a[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
            dp[0][j] = false, dp[i][0] = true;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(a[i-1]<=j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
bool isEqualPart(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    if(sum%2!=0) return false;
    sum = sum/2;
    return isSubsum(a, n, sum);
}
int main(){
    int a[] = {1, 5, 11, 5};
    cout<<(isEqualPart(a, 4)==true?"YES":"NO");
}