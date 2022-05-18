#include<iostream>
#include<algorithm>
using namespace std;
int minKnapsack(int a[], int n, int W){
    sort(a, a+n);
    int l = 0, r = n-1, ans = 0;
    while(l<=r){
        if(a[l]+a[r]<=W)
            ans++, l++, r--;
        else
            ans++, r--;
    }
    return ans;
}
int main(){
    int a[] = {150, 150, 150, 150, 150};
    cout<<minKnapsack(a, 5, 300);
}