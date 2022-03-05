#include<iostream>
using namespace std;
int equiPoint(int a[], int n){
    int s1 = 0;
    for(int i=0; i<n; i++)
        s1 += a[i];
    int s2 = 0, x = n-1, i;
    for(i=n-1; i>=0; i--){
        s1 -= a[i];
        if(s2==s1)
            return i+1;
        s2 += a[i];        
    }
    if(s1==s2)
        return i+1;
    return -1;
}
int main(){
    int a[] = {1, 3, 5, 2, 2};
    cout<<equiPoint(a, 5);
}