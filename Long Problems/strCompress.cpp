#include<iostream>
using namespace std;
void strCompress(string s){
    int l = s.length();
    int hash[26] = {0};
    for(int i=0; i<l; i++){
        char ch = s[i];
        i++;
        int t = 0;
        while(i<l && s[i]>='0' && s[i]<='9'){
            t = t*10 + (s[i]-'0');
            i++;
        }
        i--;
        hash[ch-'a'] += t;
    }
    for(int i=0; i<26; i++){
        if(hash[i]!=0){
            char t = i+'a';
            cout<<t<<" "<<hash[i]<<" ";
        }
    }
}
int main(){
    string s;
    cin>>s;
    strCompress(s);
}