#include<iostream>
using namespace std;
int maxFreq(string s){
    int count[26] = {0}, mx = 0;
    for(int i=0; i<s.length(); i++){
        count[s[i]-'a']++;
        mx = max(count[s[i]-'a'], mx);
    }
    return mx;
}
int main(){
    cout<<maxFreq("appllelalal");
}