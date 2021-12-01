#include<iostream>
#include<unordered_map>
using namespace std;
int firstRepeat(int a[], int n){
    unordered_map<int, int> m;
    int x[n] = {0}, mn = INT_MAX;
    for(int i=0; i<n; i++){
        x[a[i]]++;
        if(!m[a[i]])
            m[a[i]] = i;
        if(x[i]==2 && i<mn)
            mn = i;
    }
    return mn;
}

//Method 2
int firstReEle(int a[], int n){
    int m[n] = {-1}, mn = INT_MAX;
    for(int i=0; i<n; i++){
        if(m[a[i]]!=-1)
            mn = min(mn, m[a[i]]);
        else
            m[a[i]] = 1;
    }
    if(mn==INT_MAX)
        return -1;
    return mn;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<firstRepeat(a, n);
}