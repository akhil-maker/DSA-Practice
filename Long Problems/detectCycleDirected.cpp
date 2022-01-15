#include<iostream>
using namespace std;
int graph[100][100];
bool dfsUtil(int i, int visited[], int n, bool recst[]){
    visited[i] = 1;
    recst[i] = true;
    for(int j=0; j<n; j++){
        if(!visited[j] && graph[i][j]==1 && dfsUtil(j, visited, n, recst))
            return true;
        else if(recst[j]==1 && graph[i][j]==1)
            return true;
    }
    recst[i] = false;
    return false;
}
bool dfs(int n){
    int s = 0;
    int visited[n] = {0};
    bool recst[n] = {false};
    for(int i=0; i<n; i++)
        if(!visited[i] && dfsUtil(i, visited, n, recst))
            return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>graph[i][j];
    cout<<dfs(4);
}