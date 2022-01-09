#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
};
Node *newNode(int item){
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void preorder(Node *root){
    if (root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
vector<Node*> getTrees(int a[], int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<Node*> ltrees = getTrees(a, start, i-1);
        vector<Node*> rtrees = getTrees(a, i+1, end);
        for(int j=0; j<ltrees.size(); j++){
            for(int k=0; k<rtrees.size(); k++){
                Node* n = newNode(a[i]);
                n->left = ltrees[j];
                n->right = rtrees[k];
                trees.push_back(n);
            }
        }
    }
    return trees;
}
int main(){
    int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);
 
    vector<Node *> trees = getTrees(in, 0, n-1);
 
    cout << "Preorder traversals of different "<< "possible Binary Trees are \n";
    for (int i = 0; i < trees.size(); i++){
        preorder(trees[i]);
        cout<<endl;
    }
}