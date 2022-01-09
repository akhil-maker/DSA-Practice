#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int x){
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void inorder(Node* root){
    Node* p = root;
    stack<Node*> s;
    while(p!=NULL || !s.empty()){
        while(p!=NULL){
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        cout<<p->data<<" ";
        p = p->right;
    }
}
int main(){
    Node* t = newNode(5);
    Node* t1 = newNode(3);
    Node* t2 = newNode(4);
    t->left = t1;
    t->right = t2;
    Node* t3 = newNode(6);
    Node* t4 = newNode(7);
    t1->left = t3;
    t1->right = t4;
    inorder(t);
}