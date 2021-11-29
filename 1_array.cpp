#include<iostream>
using namespace std;
int main(){
    int arr[4] = {10, 20, 30, 40};
    cout<<arr[3]<<endl;
    cout<<"Enter elements:";
    for(int i=0; i<4; i++){
        int n;
        cin>>n;
        arr[i] = n;
    }
    for(int i=0; i<4; i++)
        cout<<arr[i]<<" ";

    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i=0; i<4; i++){
        if(arr[i]>mx)
            mx = arr[i];
        if(arr[i]<mn)
            mn = arr[i];
    }
    cout<<endl<<mx<<" "<<mn<<endl;
}