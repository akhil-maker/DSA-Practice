#include<iostream>
using namespace std;
int maxVal(int val[], int wt[], int W, int flag, int k, int index, int n){
    if(index>=n)
        return 0;
    if(flag==k){
        int skip = maxVal(val, wt, W, flag, k, index+1, n);
        int full = 0;
        if(wt[index]<=W)
            full = val[index]+maxVal(val, wt, W-wt[index], flag, k, index+1, n);
        return max(full, skip);
    }
    else{
        int skip = maxVal(val, wt, W, flag, k, index+1, n);
        int full = 0, half = 0;
        if(wt[index]<=W)
            half = val[index]+maxVal(val, wt, W-wt[index], flag, k, index+1, n);
        else if(wt[index]/2 <= W)
            half = val[index]+maxVal(val, wt, W-wt[index]/2, flag+1, k, index+1, n);
        return max(full, max(skip, half));
    }
}
int main(){
    int val[] = {17, 20, 10, 15};
    int wt[] = {4, 2, 7, 5};
    int k = 2, W = 8;
    cout<<maxVal(val, wt, W, 0, k, 0, 4);
}