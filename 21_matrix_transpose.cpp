#include<iostream>
#define R 3
#define C 3
using namespace std;
void transpose(int a[R][C]){
    for(int i=0; i<R; i++){
        for(int j=i; j<C; j++){
            if(i==j)
                continue;
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}
int main(){
    int a[R][C] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    transpose(a);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}