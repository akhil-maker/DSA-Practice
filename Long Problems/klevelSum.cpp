#include<iostream>
using namespace std;
int ksum(string s, int k){
    int sum = 0, l = -1;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(')
            l++;
        else if(s[i]==')')
            l--;
        else{
            if(l==k){
                int t = 0, mul = 1;
                if(s[i]=='-')
                    mul = -1;
                while(i<s.length() && s[i]-'0'>=0 && s[i]-'0'<='9'){
                    if(s[i]!='-')
                        t = t*10 + (s[i]-'0');
                    i++;
                }
                if(i<s.length() && (s[i]==')' || s[i]=='('))
                    i--;
                sum += t*mul;
            }
        }
    }
    return sum;
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    cout<<ksum(s, k);
}