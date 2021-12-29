#include<iostream>
#include<unordered_map>
using namespace std;
string remChar(string a, string b){
    unordered_map<char, int> m;
    for(int i=0; i<b.length(); i++)
        if(m[b[i]]!=1)
            m[b[i]] = 1;
    for(int i=0; i<a.length(); i++)
        if(m[a[i]]==1)
            m[a[i]] = 2;
    string r = "";
    for(int i=0; i<a.length(); i++)
        if(m[a[i]]!=2)
            r += a[i];
    for(int i=0; i<b.length(); i++)
        if(m[b[i]]!=2)
            r += b[i];
    return r;
}
int main(){
    cout<<remChar("aacdb", "gafd");
}