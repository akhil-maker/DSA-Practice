#include<iostream>
using namespace std;
int countPath(int s, int e){
    if(s==e)
        return 1;
    if(s>e)
        return 0;
    int cnt = 0;
    for(int i=1; i<=6; i++)
        cnt += countPath(s+i, e);
    return cnt;
}
int main(){
    cout<<countPath(0, 3);
}