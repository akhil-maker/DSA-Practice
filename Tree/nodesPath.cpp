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
bool getPath(Node* root, vector<int> &path, int x){
    if(root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data==x)
        return true;
    if(getPath(root->left, path, x) || getPath(root->right, path, x))
        return true;
    path.pop_back();
    return false;
}
void nodePath(Node* root, int src, int dest){
    vector<int> path1;
    vector<int> path2;
    getPath(root, path1, src);
    getPath(root, path2, dest);
    int i = 0, j = 0, intersection = -1;
    while(i!=path1.size() || j!=path2.size()){
        if(i==j && path1[i]==path2[j])
            i++, j++;
        else{
            intersection = j-1;
            break;
        }
    }
    for(int i=path1.size()-1; i>intersection; i--)
        cout<<path1[i]<<" ";
    for(int i=intersection; i<path2.size(); i++)
        cout<<path2[i]<<" ";
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(13);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    nodePath(root, 3, 15);
}