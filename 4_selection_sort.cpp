#include<iostream>
using namespace std;
void selectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[minIndex])
                minIndex = j;
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    selectionSort(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}