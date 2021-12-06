#include<iostream>
using namespace std;
bool isSorted(int a[], int n){
    if(n==0 || n==1)
        return true;
    else if(a[n-1]>a[n-2])
        return (true && isSorted(a, n-1));
    else
        return false;
}
int main(){
    int a[] = {1, 2, 7, 4, 5};
    cout<<isSorted(a, 5);
}