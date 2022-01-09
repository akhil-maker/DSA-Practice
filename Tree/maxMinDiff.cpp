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
void maxMin(int &mn, int &mx, Node* t){
    if(t==NULL)
        return;
    if(t->data<mn)
        mn = t->data;
    if(t->data>mx)
        mx = t->data;
    maxMin(mn, mx, t->left);
    maxMin(mn, mx, t->right);
}
int mxmnDiff(Node* t){
    if(t==NULL)
        return 0;
    int mx = t->data, mn = t->data;
    maxMin(mn, mx, t);
    return mx-mn;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    cout<<mxmnDiff(root);
}