#include<iostream>
using namespace std;
int fib_recur(int n){
    if(n==0 || n==1)
        return 1;
    return fib_recur(n-1)+fib_recur(n-2);
}
int fib_dp(int n){
    int fib[n+1];
    fib[0] = fib[1] = 1;
    for(int i=2; i<=n; i++)
        fib[i] = fib[i-1]+fib[i-2];
    return fib[n];
}
int main(){
    cout<<fib_dp(9);
}