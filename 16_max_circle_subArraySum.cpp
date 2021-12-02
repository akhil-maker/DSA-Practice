#include<iostream>
using namespace std;
int kadane(int a[], int n){
    int maxSum = 0, sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + a[i];
        if(maxSum<sum)
            maxSum = sum;
        if(sum<0)
            sum = 0;
    }
    return maxSum;
}
int circle_subsum(int a[], int n){
    int nonWrapSum = kadane(a, n);
    int wrapSum, tsum = 0;
    for(int i=0; i<n; i++){
        tsum += a[i];
        a[i] = -a[i];
    }
    wrapSum = tsum + kadane(a, n);
    return max(nonWrapSum, wrapSum);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<circle_subsum(a, n);
}