#include<iostream>
using namespace std;
string keyArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string code = keyArr[ch-'0'];
    string r = s.substr(1);
    for(int i=0; i<code.length(); i++)
        keypad(r, ans+code[i]);
}
int main(){ 
    keypad("23", "");
}   