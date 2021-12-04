#include<iostream>
using namespace std;
int main(){
    char a[100] = "apple";
    int i = 0;
    while(a[i]!='\0'){
        cout<<a[i]<<" ";
        i++;
    }
    return 0;
}