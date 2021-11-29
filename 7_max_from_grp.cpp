#include<iostream>
using namespace std;
void mxGrp(int a[], int n){
    int mx = a[0];
    for(int i=0; i<n; i++){
        if(a[i]>mx)
            mx = a[i];
        cout<<mx<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    mxGrp(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}