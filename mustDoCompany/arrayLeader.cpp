#include<iostream>
using namespace std;
void arrayLeaders(int a[], int n){
    int mx = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(a[i]>mx)
            cout<<a[i]<<" ";
        mx = max(mx, a[i]);
    }
}
int main(){
    int a[] = {16, 17, 4, 3, 5, 2};
    arrayLeaders(a, 6);
}