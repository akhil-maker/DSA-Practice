#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isVisited(int x, vector<int> p){
    for(int i=0; i<p.size(); i++)
        if(p[i]==x)
            return true;
    return false;
}
int min(int a, int b){
    if(a<b)
        return a;
    return b;
}
int minEdge(vector<vector<int>>& a, int src, int dest){
    vector<int> path;
    queue<vector<int>> q;
    path.push_back(src);
    q.push(path);
    int mn = INT_MAX;
    while(!q.empty()){
        path = q.front();
        q.pop();
        int last = path[path.size()-1];
        if(last==dest)
            mn = min(mn, path.size()-1);
        for(int i=0; i<a.size(); i++){
            if(a[last][i]==1 && !isVisited(i, path)){
                vector<int> p(path);
                p.push_back(i);
                q.push(p);
            }
        }
    }
    return mn;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout<<minEdge(a, 0, 5);
}