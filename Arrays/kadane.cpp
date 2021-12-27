#include<iostream>
using namespace std;
int kadane(int a[], int n){
    int sum = 0, ans = INT_MIN;
    for(int i=0; i<n; i++){
        sum = sum + a[i];
        if(sum>ans)
            ans = sum;
        if(sum<0)
            sum = 0;
    }
    return ans;
}
int main(){
    int a[] = {1, 2, 3, -2, 5};
    cout<<kadane(a, 5);
}