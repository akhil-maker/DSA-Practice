#include<iostream>
#include<algorithm>
using namespace std;
struct Train{
    int arr;
    int dept;
};
bool comp(Train a, Train b){
    return b.dept>a.dept;
}
int minPlatforms(int a[], int d[], int n){
    Train t[n];
    for(int i=0; i<n; i++)
        t[i].arr = a[i], t[i].dept = d[i];
    sort(t, t+n, comp);
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        if(t[i].dept>t[i+1].arr)
            cnt++;
    }
    return cnt==0?1:cnt;
}
int main(){
    int a[] = {900, 940, 950, 1100, 1500, 1800};
    // int a[] = {900, 1100, 1235};
    int d[] = {910, 1200, 1120, 1130, 1900, 2000};
    // int d[] = {1000, 1200, 1240};
    cout<<minPlatforms(a, d, 6);
}