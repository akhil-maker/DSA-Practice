#include<iostream>
using namespace std;
int cntPathMaze(int n, int i, int j){
    if(i==n-1 && j==n-1)
        return 1;
    if(i>=n || j>=n)
        return 0;
    return cntPathMaze(n, i+1, j)+cntPathMaze(n, i, j+1);
}
int main(){
    cout<<cntPathMaze(3, 0, 0);
}