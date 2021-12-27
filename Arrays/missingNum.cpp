#include<iostream>
using namespace std;
int missSum(int a[], int n){
    int sum = 0, tsum = (n*(n+1))/2;
    for(int i=0; i<n-1; i++)
        sum += a[i];
    return tsum-sum;
}
int main(){
    int a[] = {1, 2, 3, 5};
    cout<<missSum(a, 5);
}