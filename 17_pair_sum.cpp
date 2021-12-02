#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
void pairSum(int a[], int n, int k){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]+a[j] == k){
                cout<<a[i]<<" "<<a[j]<<endl;
                return;
            }
        }
    }
    cout<<"No pairs"<<endl;
}
void ptr2PairSum(int a[], int n, int k){
    sort(a, a+n);
    int low = 0, high = n-1;
    while(low<=high){
        if(a[low]+a[high]==k){
            cout<<a[low]<<" "<<a[high]<<endl;
            return;
        }
        else if(a[low]+a[high]<k)
            low++;
        else
            high--;
    }   
    cout<<"No pair"<<endl;
}
void hashPairSum(int a[], int n, int k){
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        if(s.find(k-a[i])!=s.end())
            s.insert(a[i]);
        else{
            cout<<a[i]<<" "<<k-a[i]<<endl;
            return;
        }
    }
    cout<<"no pair"<<endl;
}
int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    pairSum(a, n, k);
    ptr2PairSum(a, n, k);
    hashPairSum(a, n, k);
}