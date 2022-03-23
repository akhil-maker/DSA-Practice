#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfsUtil(int v, vector<vector<int>>& a, vector<int>& visited, stack<int>& s){
    visited[v] = 1;
    for(int i=0; i<a.size(); i++)
        if(a[v][i]==1 && !visited[i])
            dfsUtil(i, a, visited, s);
    s.push(v);
}
void topoSort(vector<vector<int>>& a){
    stack<int> s;
    vector<int> visited(a.size(), 0);
    for(int i=0; i<a.size(); i++)
        if(!visited[i])
            dfsUtil(i, a, visited, s);
    while(!s.empty()){
        int x = s.top();
        s.pop();
        cout<<x<<" ";
    }
}
int main(){
    vector<vector<int>> a = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
    };
    topoSort(a);
}