#include<iostream>
#define R 3
#define C 3
using namespace std;
bool search(int a[R][C], int val){
    int i = 0, j = C-1;
    while(i<R && j>=0){
        if(a[i][j]==val)
            return true;
        else if(a[i][j]>val)
            j--;
        else
            i++;
    }
    return false;
}
int main(){
    int a[R][C] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout<<search(a, 5);
}