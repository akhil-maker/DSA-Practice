#include<iostream>
using namespace std;
bool comparator(int dif, int a[], int n, int c){
    int curr = 1;
    int left = 0;
    for(int i=1; i<n; i++){
        if(a[i]-a[left]>=dif){
            left = i;
            curr++;
            if(curr==c)
                return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        int l = 0, r = a[n-1]-a[0];
        while(r>l){
            int m = (l+r)/2;
            if(comparator(m, a, n, c)==true)
                l = m+1;
            else
                r = m-1;
        }
        cout<<l<<endl;
    }
}