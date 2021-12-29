#include<iostream>
using namespace std;
bool savePal(string s){
    int i = 0, j = s.length();
    while(i<j){
        if(tolower(s[i])<'a' || tolower(s[i])>'z')
            i++;
        else if(tolower(s[j])<'a' || tolower(s[j])>'z')
            j--;
        else if(tolower(s[i])!=tolower(s[j]))
            return false;
        else
            i++, j--;   
    }
    return true;
}
int main(){
    cout<<savePal("Ab?/B a");
}