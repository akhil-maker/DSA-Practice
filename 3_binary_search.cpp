#include<iostream>
using namespace std;
int binarySearch(int a[], int n, int x){
    int low = 0, high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]<x)
            low = mid;
        else
            high = mid;
    }
    return -1;
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    int x;
    cin>>x;
    cout<<binarySearch(a, 6, x);
}