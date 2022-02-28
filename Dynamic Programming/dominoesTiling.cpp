#include<iostream>
using namespace std;
int dominosTiling(int n){
    int a[n+1], b[n+1];
    a[0] = 1, a[1] = 0, b[0] = 0, b[1] = 1;
    for(int i=2; i<n+1; i++){
        a[i] = a[i-2]+2*b[i-1];
        b[i] = a[i-1]+b[i-2];
    }
    return a[n];
}
int main(){
    cout<<dominosTiling(8);
}