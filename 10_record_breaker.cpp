#include<iostream>
using namespace std;
int recordBreaker(int a[], int n){
    int mx = INT_MIN, cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]>mx && a[i]>a[i+1]){
            mx = a[i];
            cnt++;
        }
        mx = max(a[i], mx);
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<recordBreaker(a, n);
}