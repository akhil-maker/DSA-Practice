#include<iostream>
using namespace std;
int xb, yb, xt, yt;
int sinkField(int dp[1001][1001], int n, int m, int k){
    int msum = INT_MAX;
    for(int i=0; i<=n-k; i++){
        for(int j=0; j<=m-k; j++){
            int sum = dp[i+k][j+k]-dp[i+k][j]-dp[i][j+k]+dp[i][j];
            if(sum<msum){
                msum = sum;
                if(msum<=1){
                    xb = i+k;
                    yb = j+1;
                    xt = i+1;
                    yt = j+k;
                }
            }
        }
    }
    return msum;
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n, m;
        cin>>n>>m;
        int k;
        cin>>k;
        int a[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                a[i][j] = 0;
        int x, y;
        for(int i=0; i<k; i++){
            cin>>x>>y;
            a[x-1][y-1] = 1;
        }
        int dp[1001][1001];
        for(int i=0; i<1001; i++)
            for(int j=0; j<1001; j++)
                dp[i][j] = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i-1][j-1];
        int l = 1, r = min(n, m);
        int ones;
        while(l<r){
            int mid = (l+r)/2;
            ones = sinkField(dp, n, m, mid);
            if(ones>1)
                r = mid;
            else
                l = mid+1;
        }
        cout<<xb<<" "<<yb<<" "<<xt<<" "<<yt<<endl;
    }
}