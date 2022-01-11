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
bool sameLvlLeaves(Node* root){
    int lvl = 0, level = INT_MAX;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node* p = q.front();
        q.pop();
        if(p==NULL){
            q.push(NULL);
            lvl++;
        }
        else{
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            if(p->left==NULL && p->right==NULL && level==INT_MAX)
                level = lvl;
            if(p->left==NULL && p->right==NULL && level!=INT_MAX && level!=lvl)
                return false;
        }
    }
    return true;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    cout<<sameLvlLeaves(root);
}