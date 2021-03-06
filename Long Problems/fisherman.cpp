#include<iostream>
using namespace std;
int gates[3], fisherman[3];
int visited[20], n, ans = 99999999;
void permut(int visited[], int l, int r){
    if(l==r){
        int i, j, k, dist = 0;
        for(i=0; i<fisherman[0]; i++)
            dist = dist + abs(visited[i]-gates[0]);
        for(j=0; j<fisherman[1]; j++){
            dist = dist + abs(visited[i]-gates[1]);
            i++;
        }
        for(k=0; k<fisherman[2]; k++){
            dist = dist + abs(visited[i]-gates[2]);
            i++;
        }
        dist = dist + i;
        ans = min(ans, dist);
        return;
    }
    else{
        for(int i=l; i<=r; i++){
            swap(visited[i], visited[l]);
            permut(visited, l+1, r);
            swap(visited[i], visited[l]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<3; i++)
            cin>>gates[i];
        for(int i=0; i<3; i++)
            cin>>fisherman[i];
        for(int i=0; i<n; i++)
            visited[i] = i+1;
        permut(visited, 0, n-1);
        cout<<ans<<endl;
    }
}