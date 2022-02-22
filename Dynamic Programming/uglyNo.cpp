#include<iostream>
using namespace std;
int ugly(int n){
    int ugly[n];
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0, next_mul2 = ugly[i2]*2, next_mul3 = ugly[i3]*3, next_mul5 = ugly[i5]*5;
    int next_uglyno = 1;
    for(int i=1; i<n; i++){
        next_uglyno = min(next_mul2, min(next_mul3, next_mul5));
        ugly[i] = next_uglyno;
        if(next_mul2==next_uglyno){
            i2 = i2+1;
            next_mul2 = ugly[i2]*2;
        }
        if(next_mul3==next_uglyno){
            i3 = i3+1;
            next_mul3 = ugly[i3]*3;
        }
        if(next_mul5==next_uglyno){
            i5 = i5+1;
            next_mul5 = ugly[i5]*5;
        }
    }
    return next_uglyno;
}
int main(){
    cout<<ugly(150);
}