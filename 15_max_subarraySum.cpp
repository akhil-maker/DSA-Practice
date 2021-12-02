#include<iostream>
using namespace std;
int kadane(int a[], int n){
    int maxSum = 0, sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + a[i];
        if(sum>maxSum)
            maxSum = sum;
        if(sum<0)
            sum = 0;
    }
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<kadane(a, n);
}