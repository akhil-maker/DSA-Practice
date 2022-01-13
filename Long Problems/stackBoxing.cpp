#include<iostream>
using namespace std;
struct Box{
    int l, b, h; //b<=l
};
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
int compare(const void *a, const void *b){
    return ((*(Box *)b).l*(*(Box*)b).b) - ((*(Box*)a).l*(*(Box*)a).b);
}
int maxHeight(Box a[], int n){
    Box gen[3*n];
    int ind = 0;
    for(int i=0; i<n; i++){
        gen[ind].h = a[i].h;
        gen[ind].b = min(a[i].b, a[i].l);
        gen[ind].l = max(a[i].b, a[i].l);
        ind++;
        gen[ind].h = a[i].b;
        gen[ind].b = min(a[i].h, a[i].l);
        gen[ind].l = max(a[i].h, a[i].l);
        ind++;
        gen[ind].h = a[i].l;
        gen[ind].b = min(a[i].h, a[i].b);
        gen[ind].l = max(a[i].h, a[i].b);
        ind++;
    }
    n = 3*n;
    qsort(gen, n, sizeof(gen[0]), compare);
    int msh[n];
    for(int i=0; i<n; i++)
        msh[i] = gen[i].h;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(gen[i].b<gen[j].b && gen[i].l<gen[j].l && msh[i]<msh[j]+gen[i].h)
                msh[i] = msh[j]+gen[i].h;
        }
    }
    int mx = -1;
    for(int i=0; i<n; i++)
        if(mx<msh[i])
            mx = msh[i];
    return mx;
}
int main(){
    Box a[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    cout<<maxHeight(a, 4);
}