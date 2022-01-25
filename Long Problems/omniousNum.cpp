#include<iostream>
using namespace std;
int omnious(int a, int b, int rem[], int n, int k){
    int cnt = 0;
    for(int i=a; i<=b; i++){
        int temp = i;
        int num[10] = {0};
        while(temp){
            num[temp%10]++;
            temp /= 10;
        }
        int r = 0;
        for(int i=0; i<n; i++)
            r += num[rem[i]];
        if(r<k)
            cnt++;
    }
    return cnt;
}
int main(){
    int a, b, n;
    cin>>a>>b>>n;
    int rem[n];
    for(int i=0; i<n; i++)
        cin>>rem[i];
    int k;
    cin>>k;
    cout<<omnious(a, b, rem, n, k);
}