#include<iostream>
using namespace std;
int kadane(int a[], int n){
    int currSum = 0, maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        currSum += a[i];
        if(currSum>maxSum)
            maxSum = currSum;
        if(currSum<0)
            currSum = 0;
    }
    if(maxSum<=0)
        for(int i=0; i<n; i++)
            maxSum = max(maxSum, a[i]);
    return maxSum;
}
int main(){
    int a[] = {-1, -2, -3, -4, -5};
    cout<<kadane(a, 5);
}