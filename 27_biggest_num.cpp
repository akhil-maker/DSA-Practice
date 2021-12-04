#include<iostream>
using namespace std;
string bigNum(string s){
    string x = "";
    int a[10] = {0};
    for(int i=0; i<s.length(); i++)
        a[s[i]-'0']++;
    for(int i=9; i>=0; i--){
        while(a[i]--)
            x += (i+'0');
    }
    return x;
}
int main(){
    cout<<bigNum("498723659");
}