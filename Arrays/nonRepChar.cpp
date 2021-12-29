#include<iostream>
#include<unordered_map>
using namespace std;
char nonRepeat(string s){
    unordered_map<char, int> m;
    unordered_map<char, int> m1;
    for(int i=0; i<s.length(); i++)
        if(m.count(s[i])==0)
            m[s[i]] = i;

    for(int i=0; i<s.length(); i++)
        m1[s[i]]++;
    
    int ans = INT_MAX;
    for(auto i: m){
        if(m1[i.first]==1 && i.second<ans)
            ans = i.second;
    }
    if(ans==INT_MAX)
        return -1;
    return s[ans];
}
int main(){
    string s = "zxvczbtxyzvy";
    cout<<nonRepeat(s);
}