#include<iostream>
using namespace std;
int binCoeff(int n, int k){
    int b[n+1][k+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i, k); j++){
            if(j==0 || j==i)
                b[i][j] = 1;
            else
                b[i][j] = b[i-1][j-1] + b[i-1][j];
        }
    }
    return b[n][k];
}
int main(){
    cout<<binCoeff(5, 2);
}