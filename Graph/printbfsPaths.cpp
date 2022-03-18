#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void printPath(vector<int>& x){
    for(int i=0; i<x.size(); i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
bool isVisited(int x, vector<int> path){
    for(int i=0; i<path.size(); i++)
        if(path[i]==x)
            return 1;
    return 0;
}
void bfsPaths(vector<vector<int>>& a, int src, int dest){
    int s = src;
    vector<int> path;
    path.push_back(s);
    queue<vector<int>> q;
    q.push(path);
    while(!q.empty()){
        path = q.front();
        q.pop();
        int last = path[path.size()-1];
        if(last==dest)
            printPath(path);
        for(int i=0; i<a.size(); i++){
            if(a[last][i]==1 && !isVisited(i, path)){
                vector<int> p(path);
                p.push_back(i);
                q.push(p);
            }
        }
    }
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
    };
    bfsPaths(a, 2, 3);
}