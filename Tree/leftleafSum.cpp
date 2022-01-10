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
int sumOfLL(Node* t){
    if(t==NULL)
        return 0;
    int sum = 0;
    if(t->left!=NULL && t->left->left==NULL && t->left->right==NULL)
        sum += t->left->data;
    else
        sum += sumOfLL(t->left);
    sum += sumOfLL(t->right);
    return sum;
}
int sumOfLeftLeaves(Node* t){
    if(t==NULL)
        return 0;
    stack<Node*> s;
    s.push(t);
    int sum = 0;
    while(!s.empty()){
        Node* t = s.top();
        s.pop();
        if(t->left!=NULL){
            s.push(t->left);
            if(t->left->left==NULL && t->left->right==NULL)
                sum += t->left->data;
        }
        if(t->right)
            s.push(t->right);
    }
    return sum;
}
int main(){
    Node *root = newNode(20);
    root->left= newNode(9);
    root->right = newNode(49);
    root->right->left = newNode(23);
    root->right->right= newNode(52);
    root->right->right->left = newNode(50);
    root->left->left = newNode(5);
    root->left->right = newNode(12);
    root->left->right->right = newNode(12);
    cout<<sumOfLL(root)<<endl<<sumOfLeftLeaves(root);
}