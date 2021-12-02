#include<iostream>
#define C 3
using namespace std;
int search(int a[][C], int m, int n, int k){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]==k){
                cout<<i<<" "<<j<<endl;
                return 1;
            }
        }   
    }
    return -1;
}
int main(){
    int m, n, k;
    cin>>m>>n>>k;
    int a[m][C];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    search(a, m, n, k);
}