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
void verticalTraversal(Node* root){
    queue<Node*> q;
    map<Node*, int> m;
    int hd = 0;
    q.push(root);
    m[root] = hd;
    Node* t;
    int mn = INT_MAX;
    int mx = INT_MIN;
    while(!q.empty()){
        t = q.front();
        q.pop();
        hd = m[t];
        if(t->left!=NULL){
            m[t->left] = hd-1;
            q.push(t->left);
        }
        if(t->right!=NULL){
            m[t->right] = hd+1;
            q.push(t->right);
        }
        mn = min(mn, hd);
        mx = max(mx, hd);
    }
    int i = mn;
    while(i<=mx){
        for(auto v: m){
            if(v.second==i)
                cout<<v.first->data<<" ";
        }
        cout<<endl;
        i++;
    }
}
int main(){
    Node* root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(3);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    verticalTraversal(root);
}