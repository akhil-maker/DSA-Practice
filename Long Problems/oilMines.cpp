#include<iostream>
using namespace std;
int com, mines, ans;
void solve(int i, int *a, bool *visited, int mn, int mx, int sum, int nodes, int &ans){
    if(visited[i]){
        int newmn = min(sum, mn);
        int newmx = min(sum, mx);
        if(nodes==com-1){
            ans = min(ans, newmx-newmn);
            return;
        }
    }
    visited[i] = 1;
    int j = (i+1)%mines;
    solve(j, a, visited, mn, mx, sum+a[i], nodes, ans);
    int newmn = min(sum, mn);
    int newmx = max(sum, mx);
    solve(j, a, visited, newmn, newmx, a[i], nodes+1, ans);
    visited[i] = 0;
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>com>>mines;
        int *a = new int[mines+1];
        bool *visited = new bool[mines+1];
        for(int i=0; i<mines; i++){
            cin>>a[i];
            visited[i] = false;
        }
        ans = INT_MAX;
        for(int i=0; i<mines; i++)
            solve(i, a, visited, INT_MAX, INT_MIN, 0, 0, ans);
        cout<<ans<<endl;
    }
}