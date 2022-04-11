#include<iostream>
using namespace std;
int cntOne(int n){
    int cnt = 0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}
int main(){
    cout<<cntOne(19);
}