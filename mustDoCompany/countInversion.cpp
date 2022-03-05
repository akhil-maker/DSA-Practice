#include<iostream>
using namespace std;
int cntInversion(int a[], int n){
    int cnt = 0;
    for(int i=n-1; i>=0; i--)
        for(int j=0; j<i; j++)
            if(a[j]>a[i])
                cnt++;
    return cnt;
}
int merge(int a[], int low, int mid, int high){
    int n1 = mid-low+1, n2 = high-mid;
    int left[n1], right[n2];
    for(int i=0; i<n1; i++)
        left[i] = a[low+i];
    for(int i=0; i<n2; i++)
        right[i] = a[mid+i+1];
    int i = 0, j = 0, k = low, res = 0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k] = left[i];
            k++, i++;
        }
        else{
            a[k] = right[j];
            j++, k++;
            res += (n1-i);
        }
    }
    while(i<n1){
        a[k] = left[i];
        k++, i++;
    }
    while(j<n2){
        a[k] = right[j];
        k++, j++;
    }
    return res;
}
int countInversion(int a[],int low, int high){
    int r = 0;
    if(high>low){
        int mid = (low+high)/2;
        r += countInversion(a, low, mid);
        r += countInversion(a, mid+1, high);
        r += merge(a, low, mid, high);
    }
    return r;
}
int inversionCount(int a[], int n){
    return countInversion(a, 0, n-1);
}
int main(){
    int a[] = {2, 4, 1, 3, 5};
    cout<<cntInversion(a, 5)<<endl;
    cout<<inversionCount(a, 5);
}