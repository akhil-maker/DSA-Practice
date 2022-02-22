#include<iostream>
using namespace std;
int catalan(int n){
    int cat[n+1];
    cat[0] = cat[1] = 1;
    for(int i=2; i<=n; i++){
        cat[i] = 0;
        for(int j=0; j<i; j++)
            cat[i] += cat[j]*cat[i-j-1];
    }
    return cat[n];
}
long int binomialCoeff(int n, int k){
    long int r = 1;
    if(k>n-k)
        k = n-k;
    for(int i=0; i<k; i++){
        r *= (n-i);
        r /= (i+1);
    }
    return r;
}
long int catalan_bin(int n){
    long int c = binomialCoeff(2*n, n);
    return c/(n+1);
}
int main(){
    cout<<catalan(9)<<endl<<catalan_bin(9);
}