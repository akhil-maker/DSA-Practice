#include<iostream>
using namespace std;
int missNum(int a[], int n){
    int sum = 0;
    for(int i=0; i<n-1; i++)
        sum += a[i];
    return ((n*(n+1))/2) - sum;
}
int main(){
    int a[] = {6, 1, 2, 8, 3, 4, 7, 10, 5};
    cout<<missNum(a, 10);
}