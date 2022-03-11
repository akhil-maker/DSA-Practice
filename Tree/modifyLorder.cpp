#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data){
    Node* t = new Node;
    t->data = data;
    t->left = t->right = NULL;
    return t;
}
void modifyLorder(Node* root){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->data;
        return;
    }
    queue<Node*> q;
    stack<Node*> s;
    Node* t = NULL;
    int sz, ct = 0;
    bool rTol = false;
    q.push(root);
    while(!q.empty()){
        ct++;
        sz = q.size();
        for(int i=0; i<sz; i++){
            t = q.front();
            q.pop();
            if(rTol==false)
                cout<<t->data<<" ";
            else
                s.push(t);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        if(rTol==true){
            while(!s.empty()){
                t = s.top();
                s.pop();
                cout<<t->data<<" ";
            }
        }
        if(ct==2){
            rTol = !rTol;
            ct = 0;
        }
        cout<<endl;
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
    modifyLorder(root);
}