#include<iostream>
#include<vector>
using namespace std;
bool isCyclicUtil(vector<vector<int>>& a, int v, vector<bool>& visited, vector<bool>& recStack){
    if(visited[v]==false){
        visited[v] = true;
        recStack[v] = true;
        for(int i=0; i<a.size(); i++){
            if(!visited[i] && a[v][i]==1 && isCyclicUtil(a, i, visited, recStack))
                return true;
            else if(a[v][i]==1 && recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}
bool isCyclic(vector<vector<int>>& a){
    vector<bool> visited(a.size(), false);
    vector<bool> recStack(a.size(), false);
    for(int i=0; i<a.size(); i++)
        if(!visited[i] && isCyclicUtil(a, i, visited, recStack))
            return true;
    return false;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1}
    };
    cout<<isCyclic(a);
}