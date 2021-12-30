#include<iostream>
using namespace std;
void allSubstr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string r = s.substr(1);
    allSubstr(r, ans);
    allSubstr(r, ans+ch);
}
int main(){
    allSubstr("ABC", "");
}