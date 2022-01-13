#include<iostream>
using namespace std;
int mxn = 129, white = 0, blue = 0;
int a[129][129];
bool checkSame(int sti, int stj, int size){
    bool color = a[sti][stj];
    for(int i=sti; i<sti+size; i++){
        for(int j=stj; j<stj+size; j++){
            if(a[i][j]!=color)
                return false;
        }
    }
    return true;
}
void solve(int size, int sti, int stj){
    bool same = checkSame(sti, stj, size);
    if(!same){
        solve(size/2, sti, stj);
        solve(size/2, sti+size/2, stj);
        solve(size/2, sti, stj+size/2);
        solve(size/2, sti+size/2, stj+size/2);
    }
    else
        a[sti][stj]?++blue:++white;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        white = 0, blue = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        solve(n, 0, 0);
        cout<<white<<" "<<blue<<endl;
    }
}

