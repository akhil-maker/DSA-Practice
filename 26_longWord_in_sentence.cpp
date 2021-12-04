#include<iostream>
using namespace std;
int longWord(string s){
    int i = 0, mx = -1, curr = 0;
    while(1){
        if(s[i]==' ' || i==s.length()){
            if(curr>mx)
                mx = curr;
            curr = 0;
        }
        if(s[i]!=' ')
            curr++;
        if(i==s.length())
            break;
        i++;
    }
    return mx;
}
int main(){
    cout<<longWord("you will become successful");
}