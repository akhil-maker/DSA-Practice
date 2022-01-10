#include<bits/stdc++.h>
using namespace std;
int search(int a[], int x, int n){
    for(int i=0; i<n; i++)
        if(a[i]==x)
            return i;
    return -1;
}
void inPreTopost(int in[], int pre[], int n){
    int root = search(in, pre[0], n);
    if(root!=0)
        inPreTopost(in, pre+1, root);
    if(root!=n-1)
        inPreTopost(in+root+1, pre+root+1, n-root-1);
    cout<<pre[0]<<" ";
}
int main(){
    int in[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(in)/sizeof(in[0]);
    inPreTopost(in, pre, n);
}