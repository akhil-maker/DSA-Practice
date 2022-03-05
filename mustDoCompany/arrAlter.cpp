#include<iostream>
using namespace std;
void solve(int arr[], int n){
    int t2 = n-1, b = n-1, a = 0;
    int cnt = 2;
    while(a < n-1){
        if(cnt>0){
            swap(arr[a], arr[t2]);
            if(t2==b)
                b--;
            cnt--;
        }
        else{
            swap(arr[a], arr[b]);
            b--;
            cnt = 2;
        }
        a++;
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main(){
    int a[] = {1, 2, 3, 4, 5};
    solve(a, 5);
}