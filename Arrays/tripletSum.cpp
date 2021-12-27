#include<iostream>
#include<algorithm>
using namespace std;
int findTriplet(int a[], int n){
    int ans = 0;
    sort(a, a+n);
    for(int i=n-1; i>=0; i--){
        int j = 0;
        int k = i-1;
        while(j<k){
            if(a[i]==a[j]+a[k]){
                cout<<a[i]<<" = "<<a[j]<<" + "<<a[k]<<endl;
                ans++, j++;
            }
            else if(a[i]>a[j]+a[k])
                j++;
            else
                k--;
        }
    }
    return ans;
}
int main(){
    int a[] = {1, 5, 3, 2, 4};
    cout<<findTriplet(a, 5);
}