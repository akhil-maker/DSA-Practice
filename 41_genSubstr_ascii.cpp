#include<iostream>
using namespace std;
void subStr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string r = s.substr(1);
    subStr(r, ans);
    subStr(r, ans+ch);
    subStr(r, ans+to_string(code));
}
int main(){
    subStr("AB", "");
}