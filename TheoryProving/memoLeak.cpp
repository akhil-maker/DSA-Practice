#include<iostream>
using namespace std;
void f(){
    cout<<"memory leak function called"<<endl;
    int *p = (int *)malloc(sizeof(int));
    return;
}
void ffree(){
    cout<<"memory not leak function called"<<endl;
    int *p = (int *)malloc(sizeof(int));
    free(p);
    return;
}
int main(){
    f();
    ffree();
}