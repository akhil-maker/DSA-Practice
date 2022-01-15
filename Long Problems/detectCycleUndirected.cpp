#include<iostream>
using namespace std;
int graph[100][100];
bool isCyclicUtil(int v, bool visited[], int parent, int n){
    visited[v] = true;
    cout<<v<<" "<<parent<<endl;
    for(int j=0; j<n; j++){
        if(!visited[j] && graph[v][j]==1 && isCyclicUtil(j, visited, v, n))
            return true;
        else if(j!=v && j!=parent && graph[v][j]==1)
            return true;
    }
    return false;
}
bool isCyclic(int n){
    bool visited[n] = {false};
    for(int i=0; i<n; i++)
        if(!visited[i] && isCyclicUtil(i, visited, -1, n))
            return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>graph[i][j];

    cout<<isCyclic(n);
}