#include<iostream>
#include<queue>
#include<vector>
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
vector<vector<int>> diagonalOrder(Node* root){
    vector<vector<int>> r;
    if(root==NULL)
        return r;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int> ans;
        while(sz--){
            Node* t = q.front();
            q.pop();
            while(t){
                ans.push_back(t->data);
                if(t->left)
                    q.push(t->left);
                t = t->right;
            }
        }
        r.push_back(ans);
    }
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
    vector<vector<int>> r = diagonalOrder(root);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}