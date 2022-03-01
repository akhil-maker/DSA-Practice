#include<iostream>
using namespace std;
void golomb(int n){
    int dp[n];
    dp[1] = 1;
    cout<<dp[1]<<" ";
    for(int i=2; i<=n; i++){
        dp[i] = 1+dp[i-dp[dp[i-1]]];
        cout<<dp[i]<<" ";
    }
}
int main(){
    golomb(4);
}