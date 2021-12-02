#include<iostream>
using namespace std;
int positiveMiss(int a[], int n){
    bool check[n+1] = {false};
    for(int i=0; i<n; i++){
        if(a[i]>0 && a[i]<=n)
            check[a[i]] = true;
    }
    for(int i=1; i<=n; i++)
        if(!check[i])
            return i;
    return n+1;
}
int main(){
    int a[] = {0, -9, 1, 3, -4, 5};
    cout<<positiveMiss(a, 6);
}