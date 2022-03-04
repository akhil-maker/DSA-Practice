#include<iostream>
using namespace std;
void merge(int a[], int m, int b[], int n){
    for(int i=n-1; i>=0; i--){
        int j, last = a[m-1];
        for(j=m-2; j>=0 && a[j]>b[i]; j--)
            a[j+1] = a[j];
        if(j!=m-2 || last>b[i]){
            a[j+1] = b[i];
            b[i] = last;
        }
    }
    for(int i=0; i<m; i++)
        cout<<a[i]<<" ";
    for(int j=0; j<n; j++)
        cout<<b[j]<<" ";
}
int main(){
    int a[] = {1, 3, 5, 7};
    int b[] = {0, 2, 6, 8, 9};
    merge(a, 4, b, 5);
}