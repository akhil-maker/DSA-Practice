#include<bits/stdc++.h>
using namespace std;
void printPath(vector<int> &path){
    for(int i=0; i<path.size(); i++)
        cout<<path[i]<<" ";
    cout<<endl;
}
void bfs(vector<vector<int>> &a, int src, int dest){
    vector<int> path;
    queue<vector<int>> q;
    path.push_back(src);
    q.push(path);
    while(!q.empty()){
        path = q.front();
        q.pop();
        int last = path[path.size()-1];
        if(last==dest)
            printPath(path);
        for(int j=0; j<a[last].size(); j++){
            if(find(path.begin(), path.end(), j)==path.end() && a[last][j]==1){
                vector<int> newpath(path);
                newpath.push_back(j);
                q.push(newpath);
            }
        }
    }
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };
    bfs(a, 2, 3);
}