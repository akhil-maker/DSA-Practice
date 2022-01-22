#include<iostream>
using namespace std;
int n, res;
void mrLee(int **a, bool *visited, int cnt, int cost, int src){
    if(cnt==n-1){
        if(a[src][0]!=0)
            res = min(res, cost+a[src][0]);
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[i] && a[src][i]!=0){
            visited[i] = true;
            mrLee(a, visited, cnt+1, cost+a[src][i], i);
            visited[i] = false;
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        int **a = new int*[n];
        for(int i=0; i<n; i++)
            a[i] = new int[n];
        bool* visited = new bool[n];
        for(int i=0; i<n; i++){
            visited[i] = 0;
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        }
        res = INT_MAX;
        visited[0] = true;
        mrLee(a, visited, 0, 0, 0);
        cout<<(res!=INT_MAX?res:-1)<<endl;
    }
}