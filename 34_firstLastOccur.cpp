#include<iostream>
using namespace std;
int firstOcc(int a[], int n, int i, int k){
    if(i==n)
        return -1;
    if(a[i]==k)
        return i;
    return firstOcc(a, n, i+1, k);
}
int lastOcc(int a[], int n, int i, int k){
    if(i==-1)
        return -1;
    if(a[i]==k)
        return i;
    return lastOcc(a, n, i-1, k);
}
int main(){
    int a[] = {4, 2, 1, 2, 5, 2, 7};
    cout<<firstOcc(a, 7, 0, 2)<<endl;
    cout<<lastOcc(a, 7, 7, 2)<<endl;
}