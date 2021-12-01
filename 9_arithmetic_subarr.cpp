#include<iostream>
using namespace std;
int longArithSubarr(int a[], int n){
    int cnt = 1, mx = 0, diff = a[1]-a[0];
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1] == diff)
            cnt++;
        else{
            cnt = 2;
            diff = a[i]-a[i-1];
        }
        mx = max(cnt, mx);
    }
    return mx;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<longArithSubarr(a, n);
}