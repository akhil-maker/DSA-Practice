#include<iostream>
using namespace std;
int worm[35], ans = INT_MAX, n, temp = 0;
int w[35][5];
int dist(int a, int b, int c, int d){
    return abs(b-a)+abs(d-c);
}
void wormHole(int sx, int sy, int tx, int ty, int val){
    ans = min(ans, dist(sx, sy, tx, ty)+val);
    for(int i=0; i<n; i++){
        if(worm[i]==0){
            worm[i] = 1;
            temp = dist(sx, sy, w[i][0], w[i][1])+w[i][4]+val;
            wormHole(w[i][2], w[i][3], tx, ty, temp);
            temp = dist(sx, sy, w[i][2], w[i][3])+w[i][4]+val;
            wormHole(w[i][0], w[i][1], tx, ty, temp);
            worm[i] = 0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        ans = INT_MAX;
        int sx, sy, tx, ty;
        cin>>n;
        cin>>sx>>sy>>tx>>ty;
        for(int i=0; i<n; i++){
            worm[i] = 0;
            for(int j=0; j<5; j++)
                cin>>w[i][j];
        }
        wormHole(sx, sy, tx, ty, 0);
        cout<<"case"<<i+1<<":"<<ans<<endl;
    }
}