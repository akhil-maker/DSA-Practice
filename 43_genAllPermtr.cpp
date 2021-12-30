#include<iostream>
using namespace std;
void genPermStr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        string r = s.substr(0, i)+s.substr(i+1);
        genPermStr(r, ans+ch);
    }
}
int main(){
    genPermStr("ABC", "");
}