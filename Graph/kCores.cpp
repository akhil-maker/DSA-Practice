#include<bits/stdc++.h>
using namespace std;
bool dfsUtil(vector<vector<int>>& a, int i, vector<bool>& visited, vector<int>& vdeg, int k){
    visited[i] = 1;
    for(int j=0; j<a.size(); j++){
        if(vdeg[i]<k && a[i][j]==1)
            vdeg[j]--;
        if(visited[i]==0 && a[i][j]==1)
            dfsUtil(a, j, visited, vdeg, k);
    }
    return (vdeg[i]<k);
}
void kCores(vector<vector<int>>& a, int k){
    vector<bool> visited(a.size(), false);
    vector<int> vdeg(a.size(), 0);
    int mindeg = INT_MAX;
    int startvertex;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size(); j++)
            if(a[i][j]==1)
                vdeg[i]++;
        if(mindeg>vdeg[i]){
            mindeg = vdeg[i];
            startvertex = i;
        }
    }
    dfsUtil(a, startvertex, visited, vdeg, k);
    for(int i=0; i<a.size(); i++)
        if(visited[i]==0)
            dfsUtil(a, i, visited, vdeg, k);
    for(int v=0; v<a.size(); v++){
        if(vdeg[v]>=k){
            cout<<"\n["<<v<<"]";
            for(int i=0; i<a.size(); i++)
                if(a[v][i]==1 && vdeg[i]>=k)
                    cout<<"->"<<i;
        }
    }
}
// bool DFSUtil(vector<vector<int>> &a, int i, vector<int> &visited, vector<int> &vDeg, int k){
//     visited[i] = 1;
//     for(int j=0; j<a.size(); j++){
//         if(vDeg[i]<k && a[i][j]==1)
//             vDeg[j]--;
//         if(visited[j]==0 && a[i][j]==1)
//             DFSUtil(a, j, visited, vDeg, k);
//     }
//     return (vDeg[i]<k);
// }
// void kCores(vector<vector<int>> &a, int k){
//     vector<int> visited(a.size(), 0);
//     int mindeg = INT_MAX;
//     int startvertex;
//     vector<int> vDeg(a.size());
//     for(int i=0; i<a.size(); i++){
//         for(int j=0; j<a.size(); j++)
//             if(a[i][j]==1)
//                 vDeg[i]++;
//         if(mindeg>vDeg[i]){
//             mindeg = vDeg[i];
//             startvertex = i;
//         }
//     }
//     DFSUtil(a, startvertex, visited, vDeg, k);
//     for(int i=0; i<a.size(); i++)
//         if(visited[i]==0)
//             DFSUtil(a, i, visited, vDeg, k);
//     for(int v=0; v<a.size(); v++){
//         if(vDeg[v]>=k){
//             cout<<"\n["<<v<<"]";
//             for(int i=0; i<a.size(); i++)
//                 if(a[v][i]==1 && vDeg[i]>=k)
//                     cout<<"->"<<i;
//         }
//     }
// }
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0}
    };
    kCores(a, 3);
}