#include<iostream>
using namespace std;
string replacePi(string s){
    if(s.length()<=1)
        return s;
    string r = "";
    if(s[0]=='p' && s[1]=='i')
        r = "3.14"+replacePi(s.substr(2));
    else
        r = s[0]+replacePi(s.substr(1));
    return r;
}
int main(){
    cout<<replacePi("pippxxppiixipi");
}