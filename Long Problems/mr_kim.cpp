#include<iostream>
using namespace std;
int x[20], y[20], n, ans;
int abs(int i){
    if(i>0)
        return i;
    return -i;
}
int dist(int i, int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
void solve(int x, bool visited[], int nodes, int val){
    if(nodes==n)
        ans = min(ans, val+dist(x, n+1));
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            visited[i] = true;
            solve(i, visited, nodes+1, val+dist(x, i));
            visited[i] = false;
        }
    }
}   
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        ans = INT_MAX;
        cin>>n;
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i=1; i<=n; i++)
            cin>>x[i]>>y[i];
        bool visited[n+2] = {false};
        solve(0, visited, 0, 0);
        cout<<"#"<<i+1<<" "<<ans<<endl;
    }
}