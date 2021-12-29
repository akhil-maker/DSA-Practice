#include<iostream>
using namespace std;
bool rotateStr(string a, string b){
    if(a==b)
        return true;
    if(a.length()!=b.length())  
        return false;
    for(int i=1; i<a.length(); i++){
        string r = a.substr(i, a.length())+a.substr(0, i);
        if(r==b)
            return true;
    }
    return false;
}
int main(){ 
    cout<<rotateStr("akhilisgood", "isgoodakhil");

}