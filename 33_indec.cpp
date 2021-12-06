#include<iostream>
using namespace std;
void inc(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}   
void dec(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    n--;
    dec(n);
}
int main(){
    dec(5);
    cout<<endl;
    inc(5);
}