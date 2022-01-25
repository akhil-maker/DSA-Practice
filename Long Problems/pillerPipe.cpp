#include<iostream>
using namespace std;
void solve(int a[], int p1, int p2, int n, int &ans, int vis[]){
    if(p1==p2)
        if(p1>ans)
            ans = p1;
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            vis[i] = 1;
            solve(a, p1+a[i], p2, n, ans, vis);
            solve(a, p1, p2+a[i], n, ans, vis);
            vis[i] = 0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        int vis[n] = {0};
        int ans = 0;
        solve(a, 0, 0, n, ans, vis);
        cout<<ans<<endl;
    }
}