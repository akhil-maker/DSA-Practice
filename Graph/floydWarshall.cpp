#include<bits/stdc++.h>
#define INF 99999
using namespace std;
bool negCycle(vector<vector<int>> &a){
    vector<vector<int>> dist;
    for(int i=0; i<a.size(); i++)
        dist.push_back(a[i]);
    for(int k=0; k<a.size(); k++)
        for(int i=0; i<a.size(); i++)
            for(int j=0; j<a.size(); j++)
                if(dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    for(int i=0; i<a.size(); i++)
        if(dist[i][i]<0)
            return true;
    return false;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, INF, INF},
        {INF, 0, -1, INF},
        {INF, INF, 0, 0},
        {-1, INF, INF, 0},
    };
    cout<<negCycle(a);
}