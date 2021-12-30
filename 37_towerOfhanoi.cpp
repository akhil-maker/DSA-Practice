#include<iostream>
using namespace std;
void toi(int n, char src, char dest, char h){
    if(n==0)
        return;
    toi(n-1, src, h, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    toi(n-1, h, dest, src);
}
int main(){
    toi(3, 'A', 'C', 'B');
}