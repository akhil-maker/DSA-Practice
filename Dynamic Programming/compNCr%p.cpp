#include<iostream>
using namespace std;
int nCrModp(int n, int r, int p){
    int b[n+1][r+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<r+1; j++){
            if(j==0 || j==i)
                b[i][j] = 1;
            else
                b[i][j] = (b[i-1][j-1]%p+b[i-1][j]%p)%p;
        }
    }
    return b[n][r];
}
int main(){
    cout<<nCrModp(10, 2, 13);
}