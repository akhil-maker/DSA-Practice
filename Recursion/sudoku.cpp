#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<vector<int>>& board, int r, int c, int p){
    for(int i=0; i<9; i++){
        if(board[r][i]==p)
            return false;
        if(board[i][c]==p)
            return false;
        if(board[3*(r/3)+i/3][3*(c/3)+i%3]==p)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>>& board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]==0){
                for(int p=1; p<=9; p++){
                    if(isValid(board, i, j, p)){
                        board[i][j] = p;
                        if(solve(board))
                            return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int>> board(9, vector<int>(9, 0));
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>board[i][j];
    cout<<solve(board);
}