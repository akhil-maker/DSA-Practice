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
bool isBST(Node* root){
    if(root==NULL)
        return true;
    if(root->left!=NULL && root->left->data>root->data)
        return false;
    if(root->right!=NULL && root->right->data<root->data)
        return false;
    return isBST(root->left) && isBST(root->right);
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    cout<<isBST(root);
}