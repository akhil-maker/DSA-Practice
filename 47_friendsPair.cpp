#include<iostream>
using namespace std;
int friendsPair(int n){
    if(n<=2)
        return n;
    return friendsPair(n-1)+friendsPair(n-2)*(n-1);
}
int main(){
    cout<<friendsPair(4);
}