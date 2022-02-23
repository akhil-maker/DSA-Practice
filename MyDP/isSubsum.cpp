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
int main(){
    int a[] = {2, 3, 7, 8, 10};
    cout<<((isSubsum(a, 5, 11)==true)?"YES":"NO");
}