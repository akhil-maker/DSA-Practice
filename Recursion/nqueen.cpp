#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int r, int c, vector<vector<int>>& board, int n){
    int dr = r, dc = c;
    while(r>=0 && c>=0){
        if(board[r][c]==1)
            return false;
        r--, c--;
    }
    r = dr, c = dc;
    while(c>=0){
        if(board[r][c]==1)
            return false;
        c--;
    }
    r = dr, c = dc;
    while(r<n && c>=0){
        if(board[r][c]==1)
            return false;
        r++, c--;
    }
    return true;
}
void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, int n){
    if(col==n){
        vector<int> r;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                r.push_back(board[i][j]);
        ans.push_back(r);
        return;
    }
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, board, ans, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nqueen(int n){
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, board, ans, n);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> res = nqueen(n);
    for(int i=0; i<res.size(); i++){
        vector<int> v = res[i];
        for(int j=0; j<v.size(); j++)
            cout<<v[j]<<" ";
        cout<<endl;
    }
}