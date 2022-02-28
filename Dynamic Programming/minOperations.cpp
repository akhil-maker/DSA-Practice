#include<iostream>
using namespace std;
int minOpHelper(int i, int step){
    if(i<0)
        return INT_MAX;
    if(i==0)
        return step;
    int r1 = minOpHelper(i-1, step+1);
    int r2 = (i%2==0)?minOpHelper(i/2, step+1):INT_MAX;
    return min(r1, r2);
}
int minOperations(int n){
    return minOpHelper(n, 0);
}
int dpMinOp(int n){
    if(n==0)
        return 0;
    int cnt = 0, i;
    while(1){
        if(n==0)
            break;
        if(n%2==0)
            n = n/2, cnt++;
        else
            n = n-1, cnt++;
    }
    return cnt;
}
int main(){
    cout<<minOperations(7)<<endl<<dpMinOp(7);
}