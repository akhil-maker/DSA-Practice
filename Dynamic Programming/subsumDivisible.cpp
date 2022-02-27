#include<iostream>
using namespace std;
bool modularSum(int a[], int n, int m){
    if(n>m)
        return true;
    bool dp[m] = {false};
    for(int i=0; i<n; i++){
        if(dp[0]) return true;
        bool temp[m] = {false};
        for(int j=0; j<n; j++){
            if(dp[j]==true){
                if(dp[(j+a[i])%m] == false)
                    temp[(j+a[i])%m] = true;
            }
        }
        for(int j=0; j<m; j++)
            if(temp[j])
                dp[j] = true;
        dp[a[i]%m] = true;
    }
    return dp[0];
}
int main(){
    int a[] = {3, 1, 7, 5};
    cout<<modularSum(a, 4, 6);
}