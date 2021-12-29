#include<iostream>
using namespace std;
string urlShort(int n){
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string res = "";
    while(n!=0){
        int r = n%62;
        res += base[r];
        n = n/62;
    }
    string ans = "";
    for(int i=res.length()-1; i>=0; i--)
        ans += res[i];
    return ans;
}
int main(){
    cout<<urlShort(12345);
}