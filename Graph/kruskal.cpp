#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int u, v, wt;
    node(int u, int v, int wt):
    u(u), v(v), wt(wt){}
};
bool comp(node a, node b){
    return a.wt < b.wt;
}
int findParent(int x, vector<int>& parent){
    if(x==parent[x])
        return x;
    return parent[x] = findParent(parent[x], parent);
}
void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u]<rank[v])
        parent[u] = v;
    else if(rank[u]>rank[v])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        edges.push_back(node(a, b, w));
    }
    sort(edges.begin(), edges.end(), comp);
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++)
        parent[i] = i;
    vector<int> rank(n, 0);
    int cost = 0;
    vector<pair<int, int>> mst;
    for(auto it: edges){
        if(findParent(it.v, parent)!=findParent(it.u, parent)){
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionNodes(it.u, it.v, parent, rank);
        }
    }
    cout<<cost<<endl;
    for(auto it:mst) cout<<it.first<<"--->"<<it.second<<endl;
}