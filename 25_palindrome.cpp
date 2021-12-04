#include<iostream>
using namespace std;
bool palindrome(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]!=s[s.length()-i-1])
            return false;
    }
    return true;
}
int main(){
    cout<<palindrome("racecar")<<endl;
    cout<<palindrome("ratpar");
}