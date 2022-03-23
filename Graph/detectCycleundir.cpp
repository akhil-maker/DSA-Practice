#include<iostream>
#include<vector>
using namespace std;
bool isCyclicUtil(vector<vector<int>>& a, int v, vector<bool>& visited, int parent){
    visited[v] = true;
    for(int i=0; i<a.size(); i++){
        if(a[v][i]==1 && !visited[i] && isCyclicUtil(a, i, visited, v))
            return true;
        else if(a[v][i]==1 && i!=parent)
            return true;
    }
    return false;
}
bool isCyclic(vector<vector<int>>& a){
    vector<bool> visited(a.size(), false);
    for(int i=0; i<a.size(); i++)
        if(!visited[i] && isCyclicUtil(a, i, visited, -1))
            return true;
    return false;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    cout<<isCyclic(a);
}