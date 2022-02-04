#include<iostream>
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
Node* kthSmallest(Node* root, int &k){
    if(root==NULL)
        return NULL;
    Node* l = kthSmallest(root->left, k);
    if(l!=NULL)
        return l;
    k--;
    if(k==0)
        return root;
    return kthSmallest(root->right, k);
}
Node* printkthSmallest(Node* root, int k){
    int cnt = 0;
    Node* r = kthSmallest(root, k);
    if(r==NULL)
        return NULL;
    else
        return r;
}
int main(){
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    Node* x = printkthSmallest(root, 3);
    if(x!=NULL)
        cout<<x->data;
    else
        cout<<"Not possible";
}