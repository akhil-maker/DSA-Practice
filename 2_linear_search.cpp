#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int x;
    cout<<"Enter element to search:";
    cin>>x;
    for(int i=0; i<n; i++){
        if(a[i]==x){
            cout<<"Element is found at "<<i+1<<" position";
            break;
        }
    }

}