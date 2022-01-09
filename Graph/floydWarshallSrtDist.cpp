#include<bits/stdc++.h>
#define INF 99999
using namespace std;
void printArray(vector<vector<int>> &dist){
    for(int i=0; i<dist.size(); i++){
        for(int j=0; j<dist[i].size(); j++){
            if(dist[i][j]>=99999)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
void srtDist(vector<vector<int>> &a){
    int n = a.size();
    vector<vector<int>> dist;
    for(int i=0; i<n; i++)
        dist.push_back(a[i]);
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    printArray(dist);
}
int main(){
    vector<vector<int>> a = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    srtDist(a);
}