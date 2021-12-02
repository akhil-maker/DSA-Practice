#include<iostream>
using namespace std;
int subSum(int a[], int n, int k){
    int sum = a[0], start = 0;
    for(int i=0; i<n; i++){
        while(sum>k && start<i-1){
            sum = sum - a[start];
            start++;
        }
        if(sum==k){
            cout<<start<<" "<<i-1<<endl;
            return 1;
        }
        if(i<n)
            sum = sum + a[i];
    }
    return -1;
}
int main(){
    int n, k;
    cin>>n>>k; 
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<subSum(a, n, k);
}