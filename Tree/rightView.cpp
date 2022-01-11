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
void rightView(Node* root){
    if(root==NULL)
        return;
    Node* t = root;
    queue<Node*> q;
    q.push(t);
    while(!q.empty()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            t = q.front();
            q.pop();
            if(i==1)
                cout<<t->data<<" ";
            if(t->right) q.push(t->right);
            if(t->left) q.push(t->left);
        }
    }
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    rightView(root);
}