#include<iostream>
using namespace std;
int areaChoicehelper(int a, int b, int x[], int y[], int z[], int curr, int step){
    if(a<0 || b<0)
        return step-1;
    int r = step;
    if(curr==0){
        a = a+x[0], b = b+x[1];
        int p = areaChoicehelper(a, b, x, y, z, 1, step+1);
        int q = areaChoicehelper(a, b, x, y, z, 2, step+1);
        r = max(r, max(p, q));
    }
    if(curr==1){
        a = a-y[0], b = b-y[1];
        int p = areaChoicehelper(a, b, x, y, z, 0, step+1);
        int q = areaChoicehelper(a, b, x, y, z, 2, step+1);
        r = max(r, max(p, q));
    }
    if(curr==2){
        a = a-z[0], b = b+z[1];
        int p = areaChoicehelper(a, b, x, y, z, 1, step+1);
        int q = areaChoicehelper(a, b, x, y, z, 0, step+1);
        r = max(r, max(p, q));
    }
    return r;
}
int areaChoice(int a, int b, int x[], int y[], int z[]){
    int r1 = areaChoicehelper(a, b, x, y, z, 0, 0);
    int r2 = areaChoicehelper(a, b, x, y, z, 1, 0);
    int r3 = areaChoicehelper(a, b, x, y, z, 2, 0);
    return max(r1, max(r2, r3));
}
int main(){
    int x[] = {3, 2};
    int y[] = {5, 10};
    int z[] = {20, 5};
    cout<<areaChoice(20, 8, x, y, z);
}