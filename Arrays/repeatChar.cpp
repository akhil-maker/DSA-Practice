#include<iostream>
#include<unordered_map>
using namespace std;
char repeatChar(string s){
    unordered_map<char, int> m;
    for(int i=0; i<s.length(); i++)
        m[s[i]]++;
    for(int i=0; i<s.length(); i++)
        if(m[s[i]]>1)
            return s[i];
    return '#';
}
int main(){
    cout<<repeatChar("akhilisgood");
}