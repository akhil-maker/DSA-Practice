#include<iostream>
using namespace std;
int grid[1001][1001];
int solve(int n, bool bomb, int x){
    if(n<0 || x<0 || x>4)
        return 0;
    if(grid[n][x]==2)
        return 0;
    int p=0, q=0, r=0, s=0, coin = 0;
    if(grid[n][x]==1)
        coin++;
    if(x-1>=0)
        p = solve(n-1, bomb, x-1);
    if(x+1<3)
        q = solve(n-1, bomb, x+1);
    r = solve(n-1, bomb, x);
    // cout<<p<<" "<<q<<" "<<r<<" "<<n<<endl;
    if(bomb==false){
        for(int i=n-1; i>=0; i--)
            for(int j=0; j<3; j++)
                if(grid[i][j]==2)
                    grid[i][j] = 0;
        s = solve(n-1, true, x);
    }
    // cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
    return max(p, max(q, max(r, s)))+coin;
}
int solveUtil(int n, bool bomb, int x){
    return max(solve(n, bomb, x-1), max(solve(n, bomb, x+1), solve(n, bomb, x)));
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<5; j++)
                cin>>grid[i][j];
        cout<<solveUtil(n-1, false, 1);
    }
}