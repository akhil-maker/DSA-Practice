#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int bfsUtil(vector<vector<int>>& a, map<pair<int, int>, int>& m, int v, int& mn){
    int x;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=0; i<a.size(); i++){
            if(a[x][i]==1){
                q.push(i);
                mn = min(mn, m[{x, i}]);
            }
        }
    }
    if(x==v)
        return -1;
    return x;
}
void printConnection(vector<vector<int>>& a, map<pair<int, int>, int>& m, vector<int>& endv){
    for(int i=0; i<a.size(); i++){
        if(endv[i]==0){
            int mn = INT_MAX;
            int x = bfsUtil(a, m, i, mn);
            if(x!=-1 && mn!=0)
                cout<<i<<" "<<x<<" "<<mn<<endl;
        }
    }
}
int main(){
    vector<vector<int>> a = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0}
    };
    map<pair<int, int>, int> m;
    m[{6, 3}] = 98;
    m[{4, 8}] = 72;
    m[{3, 5}] = 10;
    m[{1, 7}] = 22;
    m[{8, 6}] = 17;
    m[{2, 0}] = 66;
    vector<int> endv = {1, 0, 0, 1, 0, 1, 1, 1, 1};
    printConnection(a, m, endv);
}