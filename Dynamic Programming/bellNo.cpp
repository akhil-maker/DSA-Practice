#include<iostream>
using namespace std;
int bellNo(int n){
    int b[n+1][n+1];
    b[0][0] = 1;
    for(int i=1; i<=n; i++){
        b[i][0] = b[i-1][i-1];
        for(int j=1; j<=i; j++)
            b[i][j] = b[i-1][j-1]+b[i][j-1];
    }
    return b[n][0];
}
int main(){
    cout<<bellNo(5);
}