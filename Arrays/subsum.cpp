#include<iostream>
using namespace std;
int subsum(int a[], int n, int sum){
    int curr = a[0], start = 0;
    for(int i=1; i<=n; i++){
        while(curr>sum && start<i-1){
            curr = curr-a[start];
            start++;
        }
        if(curr==sum){
            cout<<"sum found between "<<start+1<<" and "<<i;
            return 1;
        }
        if(i<n)
            curr = curr+a[i];
    }
    cout<<"No such subarray";
    return 0;
}
int main(){
    int a[] = {1, 2, 3, 7, 5};
    subsum(a, 5, 12);
}