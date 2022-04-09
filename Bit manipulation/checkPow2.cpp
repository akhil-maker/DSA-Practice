#include<iostream>
using namespace std;
int checkPow2(int n){
    return (n && !(n & n-1));
}
int main(){
    cout<<checkPow2(2048);
}