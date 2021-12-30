#include<iostream>
using namespace std;
string moveXend(string s){
    if(s=="")
        return s;
    char ch = s[0];
    if(ch=='x')
        return moveXend(s.substr(1))+ch;
    return ch+moveXend(s.substr(1));
}
int main(){
    cout<<moveXend("axxbdxcefxhix");
}