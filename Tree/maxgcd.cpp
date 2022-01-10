#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
};
Node* newNode(int data){
    Node* p = new Node;
    p->data = data;
    p->left = p->right = NULL;
    return p;
}
int gcd(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int maxgcd(Node* t, int k){
    if(t==NULL)
        return INT_MIN;
    int maingcd = gcd(t->data, k);
    int lgcd = maxgcd(t->left, k);
    int rgcd = maxgcd(t->right, k);
    maingcd = max(maingcd, max(lgcd, rgcd));
    return maingcd;
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    root->right->right->left = newNode(7);
    cout<<maxgcd(root, 21);
}