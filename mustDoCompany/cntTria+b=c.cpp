#include<iostream>
#include<algorithm>
using namespace std;
int countTriplet1(int a[], int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i!=j && i!=k && j!=k && a[i]==a[j]+a[k])
                    cnt++;
            }
        }
    }
    return cnt/2;
}
int countTriplet2(int a[], int n){
    int freq[100] = {0};
    for(int i=0; i<n; i++)
        freq[a[i]]++;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(freq[a[i]+a[j]])
                cnt++;
        }
    }
    return cnt;
}
int main(){
    int a[] = {1, 2, 2, 3, 4};
    cout<<countTriplet1(a, 5)<<endl;
    cout<<countTriplet2(a, 5)<<endl;
}