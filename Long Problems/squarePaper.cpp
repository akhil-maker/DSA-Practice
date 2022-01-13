#include<iostream>
using namespace std;
int mat[1001][1001];
int divide(int start, int end, int cstart, int cend){
    int rows = end-start+1;
    int cols = cend-cstart+1;
    int x = mat[start][cstart];
    if(rows==1 && cols==1)
        return 1;
    int cnt = 1;
    for(int i=start; i<=end; i++){
        for(int j=cstart; j<=cend; j++){
            if(mat[i][j]!=x){
                cnt = 0;
                cnt += divide(start, end/2, cstart, cend/2)+divide(end/2 +1, end, cend/2 +1, cend)+divide(start, end/2, cend/2 +1, cend)+divide(end/2 +1, end, cstart, cend/2);
                return cnt;
            }
        }
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        cout<<divide(0, n-1, 0, n-1)<<endl;
    }
}