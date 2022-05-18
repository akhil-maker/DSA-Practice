#include<iostream>
using namespace std;
string maximum(string a, string b){
    if(a.find("0")!=-1)
        return b;
    if(b.find("0")!=-1)
        return a;
    return (a.length()>b.length())? a : b;
}
string largeNum(int arr[], int n, int k){
    string dp[n+1][k+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<k+1; j++){
            if(i==0 || j==0)
                dp[i][j] = "";
            else if(arr[i-1]<=j){
                string include = to_string(i+1)+dp[i][j-arr[i-1]];
                dp[i][j] = maximum(include, dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}
int main(){
    int arr[] = {3, 12, 9, 5, 3, 4, 6, 5, 10};
    cout<<largeNum(arr, 9, 14);
}