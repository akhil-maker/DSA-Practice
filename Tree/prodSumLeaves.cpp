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
bool isLeaf(Node* root){
    return (root->left==NULL) && (root->right==NULL);
}
int sumAndMultiplyLevelData(Node* root){
    if(root==NULL)
        return 0;
    int sum = 0, pro = 1;
    Node* p;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        p = q.front();
        q.pop();
        if(p==NULL){
            q.push(NULL);
            if(sum!=0)
                pro *= sum;
            sum = 0;
        }
        else{
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            if(isLeaf(p))
                sum += p->data;
        }
    }
    if(sum!=0)
        pro *= sum;
    return pro;
}
int main(){
    Node* root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(10);
 
    cout << "Final product value = "<<sumAndMultiplyLevelData(root);
 
    return 0;
}