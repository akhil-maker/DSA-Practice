#include<iostream>
using namespace std;
int largeDivsub(int a[], int n){
    int dp[n];
    dp[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        int mxm = 0;
        for(int j=i+1; j<n; j++)
            if(a[i]%a[j]==0 || a[j]%a[i]==0)
                mxm = max(mxm, dp[j]);
        dp[i] = mxm+1;
    }
    int r = 0;
    for(int i=0; i<n; i++)
        r = max(r, dp[i]);
    return r;
}
int main(){
    int a[] = {1, 3, 6, 13, 17, 18};
    cout<<largeDivsub(a, 6);
}