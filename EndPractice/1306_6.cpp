//6
#include<iostream>
#include<vector>
using namespace std;
int f(vector<int>& a){
    int n = a.size();
    vector<int> dp(n);
    dp[0] = a[0];
    for(int i=1; i<n; i++){
        int take = 0, ntake = 0;
        take = a[i] + (i>1)?dp[i-2]:0;
        ntake = dp[i-1];
        dp[i] = min(take, ntake);
    }
    return dp[n-1];
}
long long int giveMoney(vector<int>& arr){
    vector<int> t1;
    vector<int> t2;
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(i!=0) t1.push_back(arr[i]);
        if(i!=n-1) t2.push_back(arr[i]);
    }
    int r1 = f(t1);
    int r2 = f(t2);
    return max(r1, r2);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<giveMoney(arr);
}