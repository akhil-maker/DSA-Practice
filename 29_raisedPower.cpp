#include<iostream>
using namespace std;
int raisedPower(int a, int p){
    if(p==0)
        return 1;
    return a*raisedPower(a, p-1);
}
int main(){
    cout<<raisedPower(5, 6);
}