#include<iostream>
#define R1 4
#define C1 4
#define R2 4
#define C2 4
using namespace std;
void mulmat(int m[R1][C1], int n[R2][C2]){
    int res[R1][C2];
    for(int i=0; i<R1; i++){
        for(int j=0; j<C2; j++){
            res[i][j] = 0;
            for(int k=0; k<R2; k++)
                res[i][j] += m[i][k]*n[k][j];
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int m[R1][C1] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};
    int n[R2][C2] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    mulmat(m, n);
}