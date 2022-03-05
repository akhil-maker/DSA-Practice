#include<iostream>
using namespace std;
void sort012(int a[], int n){
    int z = 0, o = 0, t = 0;
    for(int i=0; i<n; i++){
        if(a[i]==0)
            z++;
        else if(a[i]==1)
            o++;
        else if(a[i]==2)
            t++;
    }
    int i = 0;
    while(z--)
        a[i++] = 0;
    while(o--)
        a[i++] = 1;
    while(t--)
        a[i++] = 2;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[] = {0, 2, 1, 2, 0};
    sort012(a, 5);
}