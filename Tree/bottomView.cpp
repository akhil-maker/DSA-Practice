#include<iostream>
#include<map>
#include<queue>
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
vector<int> bottomView(Node* root){
    map<int, int> m1;
    map<Node*, int> m;
    queue<Node*> q;
    q.push(root);
    int hd = 0;
    m[root] = hd;
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        hd = m[t];
        m1[hd] = t->data;
        if(t->left){
            m[t->left] = hd-1;
            q.push(t->left);
        }
        if(t->right){
            m[t->right] = hd+1;
            q.push(t->right);
        }
    }
    vector<int> r;
    for(auto i=m1.begin(); i!=m1.end(); i++)
        r.push_back(i->second);
    return r;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    vector<int> r = bottomView(root);
    for(int i=0; i<r.size(); i++)
        cout<<r[i]<<" ";
}