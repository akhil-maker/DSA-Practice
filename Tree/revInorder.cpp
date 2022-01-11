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
void revInorder(Node* p){
    queue<Node*> q;
    stack<Node*> s;
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        s.push(p);
        if(p->right) q.push(p->right);
        if(p->left) q.push(p->left);
    }
    while(!s.empty()){
        p = s.top();
        s.pop();
        cout<<p->data<<" ";
    }
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    revInorder(root);
}