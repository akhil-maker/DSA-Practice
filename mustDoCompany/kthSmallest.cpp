#include<iostream>
using namespace std;
int kthSmallest(int a[], int n, int k){
    int r[k] = {INT_MAX};
    for(int i=0; i<n; i++){
        int b = 0;
        while(r[b]<a[i])
            b++;
        if(b<k)
            r[b] = a[i];
    }
    return r[k-1];
}
int main(){
    int a[] = {7, 10, 4, 3, 20, 15};
    cout<<kthSmallest(a, 6, 3);
}