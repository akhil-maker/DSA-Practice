#include<iostream>
using namespace std;
void rearrAlter(int a[], int n){
    int i = 0, j = n-1;
    int k = a[0];
    while(i<j){
        a[i] = a[j];
        int p = a[i+1];
        a[i+1] = k;
        k = p;
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"k="<<k;
        cout<<endl;
        i++, j--;
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    rearrAlter(a, 11);
}