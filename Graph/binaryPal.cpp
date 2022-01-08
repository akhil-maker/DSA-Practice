#include<bits/stdc++.h>
using namespace std;
void dfs(int parent, int ans[], vector<int> connect[]){
    ans[parent] = 1;
    for(int i=0; i<connect[parent].size(); i++){
        if(!ans[connect[parent][i]])
            dfs(connect[parent][i], ans, connect);
    }
}
void printBinPal(int n, int k){
    int a[n], ans[n] = {0};
    vector<int> connect[k];
    for(int i=0; i<n; i++)
        a[i] = i%k;
    for(int i=0; i<n/2; i++){
        connect[a[i]].push_back(a[n-i-1]);
        connect[a[n-i-1]].push_back(a[i]);
    }
    dfs(0, ans, connect);
    for(int i=0; i<n; i++)
        cout<<ans[a[i]];
}
int main(){
    printBinPal(10, 4);
}