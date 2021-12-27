#include<iostream>
using namespace std;
void merge(int a[], int b[], int m, int n){
    int i = 0, j = 0;
    while(i<m && j<n){
        if(b[j]<a[i]){
            swap(b[j], a[i]);

            while(j+1<n && b[j]>b[j+1]){
                swap(b[j], b[j+1]);
                j++;
            }
        }
        while(i+1<m && j>0 && b[j]<a[i+1])
            j--;
        if(j<0)
            j++;
        i++;
    }
    for(int i=0; i<m; i++)
        cout<<a[i]<<" ";
    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";
}
int main(){
    int a[] = {1, 3, 5, 7};
    int b[] = {0, 2, 6, 8, 9};
    merge(a, b, 4, 5);
}