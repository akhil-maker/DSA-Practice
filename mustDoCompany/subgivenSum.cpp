#include<iostream>
#include<unordered_map>
using namespace std;
void solve1(int a[], int n, int sum){
    int start = -1, end = -1;
    for(int i=0; i<n; i++){
        start = i+1;
        int s = a[i];
        for(int j=i+1; j<n; j++){
            if(s==sum){
                end = j;
                break;
            }
            s += a[j];
        }
        if(s==sum && end==-1){
            end = n;
            break;
        }
        else if(s==sum)
            break;
    }
    cout<<start<<" "<<end<<endl;
}
void solve2(int a[], int n, int sum){
    int i=0, s = 0, start = 0, end;
    while(i<n){
        s += a[i];
        if(s>sum){
            while(s>sum){
                s -= a[start];
                start++;
            }
        }
        if(s==sum){
            end = i;
            break;
        }
        i++;
    }
    cout<<(start+1)<<" "<<(end+1)<<endl;
}
//handle negative numbers
void solve3(int a[], int n, int sum){
    unordered_map<int, int> m;
    int cs = 0;
    for(int i=0; i<n; i++){
        cs += a[i];
        if(cs==sum){
            cout<<1<<" "<<i+1<<endl;
            return;
        }
        if(m.find(cs-sum)!=m.end()){
            cout<<m[cs-sum]+2<<" "<<i+1<<endl;
            return;
        }
        m[cs] = i;
    }
    cout<<"No such subarray"<<endl;
}
int main(){
    int a[] = {1, 2, 3, 7, 5};
    solve1(a, 5, 12);
    solve2(a, 5, 12);
    solve3(a, 5, 12);
}