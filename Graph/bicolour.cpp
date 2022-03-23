// C++ program to check if a connected
// graph is bipartite or not using DFS
#include <bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isfine(vector<int> adj[], int v,
                 vector<bool>& visited, vector<int>& color)
{
 
    for (int u : adj[v]) {
        if (visited[u] == false) {
            visited[u] = true;
            color[u] = !color[v];
 
            if (!isfine(adj, u, visited, color))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}
 
// Driver Code
int main()
{
    // no of nodes
    int t;
    cin>>t;
    while(t--){
        int N, m;
        cin>>N>>m;

        vector<int> adj[N + 1];
 
       vector<bool> visited(N + 1);
 
       vector<int> color(N + 1);
    
        for(int i=0; i<m; i++){
            int x, y;
            cin>>x>>y;
            addEdge(adj, x, y);
        }
 
       visited[1] = true;
 
       color[1] = 0;
 
       if (isfine(adj, 1, visited, color)) {
            int cnt = 0;
            for(int i=1; i<color.size(); i++)
                if(color[i]==0)
                    cnt++;
            cout<<max(cnt, N-cnt)<<endl;
        }
        else {
            cout << "NO"<<endl;
        }
    }
 
    return 0;
}
// Driver program to test above function
// int main()
// {
//     Graph g1(3);
//     g1.addEdge(0, 1);
//     g1.addEdge(1, 2);
//     cout << "Coloring of graph 1 \n";
//     g1.greedyColoring();
 
//     Graph g2(5);
//     g2.addEdge(0, 1);
//     g2.addEdge(0, 2);
//     g2.addEdge(1, 2);
//     g2.addEdge(1, 4);
//     g2.addEdge(2, 4);
//     g2.addEdge(4, 3);
//     cout << "\nColoring of graph 2 \n";
//     g2.greedyColoring();
 
//     return 0;
// }
// #include<iostream>
// #include<vector>
// #include<queue>
// #include<unordered_map>
// using namespace std;
// int max(int a, int b){
//     if(a>b) return a;
//     return b;
// }
// int bfsUtil(vector<vector<int>>& a, int x){
//     queue<int> q;
//     q.push(x);
//     vector<bool> visited(a.size(), false); 
//     unordered_map<int, bool> m;
//     m[x] = true;
//     int cnt = 0;
//     while(!q.empty()){
//         x = q.front();
//         q.pop();
//         for(int i=0; i<a.size(); i++){
//             if(!visited[i] && a[x][i]==1){
//                 visited[i] = true;
//                 q.push(i);
//                 m[i] = !m[x];
//             }
//         }
//     }
//     for(int i=0; i<a.size(); i++)
//         if(m[i]==true)
//             cnt++;
//     return max(cnt, a.size()-cnt);
// }
// int bfs(vector<vector<int>>& a){
//     int mx = bfsUtil(a, 0);
//     return mx;
// }
// int main(){
//     vector<vector<int>> a = {
//         {0, 1, 0, 1, 0},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 1},
//         {1, 0, 1, 0, },
//         {0, 0, 0, 0, 0}
//     };
//     int ans = bfs(a);
//     if(ans==INT_MAX)
//         cout<<"NO"<<endl;
//     else
//         cout<<ans<<endl;
// }