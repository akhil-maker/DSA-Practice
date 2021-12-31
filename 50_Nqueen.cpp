#include<iostream>
using namespace std;
bool isSafe(int** a, int x, int y, int n){
    for(int col=0; col<y; col++)
        if(a[x][col]==1)
            return false;    
    int row = x, col = y;
    while(row>=0 && col>=0){
        if(a[row][col]==1)
            return false;
        row--, col--;
    }
    row = x, col = y;
    while(row<n && col>=0){
        if(a[row][col]==1)
            return false;
        row++, col--;
    }
    return true;
}
bool nQueen(int** a, int y, int n){
    if(y>=n)
        return true;
    for(int row=0; row<n; row++){
        if(isSafe(a, row, y, n)){
            a[row][y] = 1;
            if(nQueen(a, y+1, n))
                return true;
            a[row][y] = 0;          //backracking
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int** a = new int*[n];
    for(int i=0; i<n; i++){
        a[i] = new int[n];
        for(int j=0; j<n; j++)
            a[i][j] = 0;
    }
    if(nQueen(a, 0, n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
}