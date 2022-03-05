#include<iostream>
#include<math.h>
using namespace std;
int powerPairs(int a[], int b[], int m, int n){
    int cnt = 0;
    for(int i=0; i<m; i++){
        int x = a[i];
        for(int j=0; j<n; j++){
            int y = b[j];
            if((y*log(x)-x*log(y))>0)
                cnt++;
        }
    }
    return cnt;
}
int main(){
    int a[] = {2, 3, 4, 5};
    int b[] = {1, 2, 3};
    cout<<powerPairs(a, b, 4, 3);
}