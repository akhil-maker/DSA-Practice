#include<iostream>
using namespace std;
void revGrp(int a[], int n, int k){
    int i = 0;
    while(i<n){
        int x = i+k-1, j = x;
        if(j>n-1)
            j = n-1;
        while(i<j){
            swap(a[i], a[j]);
            i++, j--;
        }
        i = x+1;
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    revGrp(a, 6, 3);
}