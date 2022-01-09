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
bool areIdentical(Node* p, Node* t){
    if(p==NULL && t==NULL)
        return true;
    else if(p==NULL || t==NULL)
        return false;
    return (p->data==t->data) && areIdentical(p->left, t->left) && areIdentical(p->right, t->right);
}
bool isSubtree(Node* p, Node* t){
    if(t==NULL)
        return true;
    if(p==NULL)
        return false;
    if(areIdentical(p, t))
        return true;
    return isSubtree(p->left, t) || isSubtree(p->right, t);
}
int main(){
    Node* p = newNode(5);
    Node* p1 = newNode(3);
    Node* p2 = newNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = newNode(1);
    p1->right = newNode(6);
    p2->left = newNode(7);
    cout<<isSubtree(p, p2);
}