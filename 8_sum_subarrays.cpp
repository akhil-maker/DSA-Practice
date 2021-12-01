#include<iostream>
using namespace std;
void sumSubarrays(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            cout<<sum<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sumSubarrays(a, n);
}