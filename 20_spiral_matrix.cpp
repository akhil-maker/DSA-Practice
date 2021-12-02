#include<iostream>
#define R 5
#define C 5
using namespace std;
void spiralMatrix(int a[R][C], int m, int n){
    int i, k=0, l=0;
    while(k<=m && l<=n){
        for(i=l; i<=n; i++)
            cout<<a[k][i]<<" ";
        k++;
        for(i=k; i<=m; i++)
            cout<<a[i][n]<<" ";
        n--;
        for(i=n; i>=l; i--)
            cout<<a[m][i]<<" ";
        m--;
        for(i=m; i>=k; i--)
            cout<<a[i][l]<<" ";
        l++;
    }
}
int main(){
    int a[R][C] = {{1, 2, 3, 4, 20}, {5, 6, 7, 8, 30}, {9, 10, 11, 12, 40}, {13, 14, 15, 16, 50}, {60, 70, 80, 90, 55}};
    spiralMatrix(a, 4, 4);
}