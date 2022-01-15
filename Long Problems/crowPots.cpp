#include<iostream>
#include<algorithm>
using namespace std;
void merge(int a[], int l, int m, int r){
    int i = l, j = m+1, k = l;
    int b[r] = {0};
    while(i<=m && j<=r){
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i<=m)
        b[k++] = a[i++];
    while(j<=r)
        b[k++] = a[j++];
    for(int i=l; i<=r; i++)
        a[i] = b[i];
}
void mergeSort(int a[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
int minPotStones(int a[], int n, int k){
    int stones = 0;
    for(int i=n-1; i>0; i--)
        a[i] = max(0, a[i]-a[i-1]);
    for(int i=0; i<k; i++)
        stones += (a[i]*(n-i));
    return stones;
}
int minStones(int a[], int n, int k){
    sort(a, a+n);
    reverse(a, a+n);
    int mn = a[n-1], i = 0;
    int res = a[i]-mn, stones = mn;
    a[i] = a[i]-mn;
    while(k>0){
        cout<<a[i]<<" "<<mn<<" "<<res<<endl;
        if(a[i]==0)
            continue;
        if(a[i]>=a[i+1])
            i++;
        if(a[i]<=mn){
            stones += a[i];
            a[i] = 0;
            k--;
            cout<<k<<endl;
            res = 0;
            if(a[n-1]==0){
                mn = a[n-2];
                n--;
                i--;
            }
            else
                i++;
        }
        else{
            res = a[i]-mn;
            a[i] = a[i]-mn;
            stones += mn;
        }
    }
    return stones;
}
int main(){
    int a[] = {65, 69};
    cout<<minStones(a, 2, 1)<<endl;
    int b[5] = {65, 69};
    mergeSort(b, 0, 1);
    for(int i=0; i<2; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    cout<<minPotStones(b, 2, 1);
}