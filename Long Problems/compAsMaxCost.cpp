#include<iostream>
using namespace std;
int D, E, F, d, e;
int config;
int ans = 0;
struct Configuration{
    int D, E, F, SPi;
};
Configuration m[9];
void solve(int index, int counta, int D, int E, int F, int cost){
    if(index>=config || counta==3){
        cost += D*d + E*e;
        if(cost>ans)
            ans = cost;
        return;
    }
    solve(index+1, counta, D, E, F, cost);
    int i = 1;
    while(true){
        if(D-m[index].D*i>=0 && E-m[index].E*i>=0 && F-m[index].F*i>=0){
            solve(index+1, counta+1, D-m[index].D*i, E-m[index].E*i, F-m[index].F*i, cost+m[index].SPi*i);
            ++i;
        }
        else
            break;  
    }
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>D>>E>>F>>d>>e;
        cin>>config;
        for(int i=0; i<config; i++)
            cin>>m[i].D>>m[i].E>>m[i].F>>m[i].SPi;
        solve(0, 0, D, E, F, 0);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}