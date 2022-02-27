#include<iostream>
#include<vector>
using namespace std;
bool dp[1001][1001];
void display(const vector<int>& r){
    for(int i=0; i<r.size(); i++)
        cout<<r[i]<<" ";
    cout<<endl;
}
void printSubsumRec(int a[], int i, int sum, vector<int>& p){
    if(i==0 && sum!=0 && dp[0][sum]){
        p.push_back(a[i]);
        if(a[i]==sum)
            display(p);
        return;
    }
    if(i==0 && sum==0){
        display(p);
        return;
    }
    if(dp[i-1][sum]){
        vector<int> b = p;
        printSubsumRec(a, i-1, sum, b);
    }
    if(sum>=a[i] && dp[i-1][sum-a[i]]){
        p.push_back(a[i]);
        printSubsumRec(a, i-1, sum-a[i], p);
    }
}
void printAllsubSum(int a[], int n, int sum){
    if(n==0 || sum<0)
        return;
    for(int i=0; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
            dp[0][j] = false, dp[i][0] = true;
    dp[0][0] = true;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(a[i-1]<=j)
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> p;
    printSubsumRec(a, n-1, sum, p);
}
int main(){
    int a[] = {1, 2, 3, 4, 5};
    printAllsubSum(a, 5, 10);
}