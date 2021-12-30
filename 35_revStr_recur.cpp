#include<iostream>
using namespace std;
string revStr(string s){
    if(s=="")
        return s;
    char c = s[0];
    string r = revStr(s.substr(1)) + c;
    return r;
}
int main(){
    cout<<revStr("binod");
}