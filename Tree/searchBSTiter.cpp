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
Node* search(Node* root, int key){
    while(root!=NULL){
        if(root->data == key)
            return root;
        else if(root->data>key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    Node* key = search(root, 6);
    cout<<key->data;
}