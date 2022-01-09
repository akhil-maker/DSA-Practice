#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node* left, *right;
};
Node* newNode(char data){
    Node* t = new Node;
    t->data = data;
    t->left = t->right = NULL;
    return t;
}
bool isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}
int solve(Node* root){
    if(root==NULL)
        return 0;
    else{
        if(!isOperator(root->data))
            return root->data;
        else{
            int a = solve(root->left);
            int b = solve(root->right);
            switch (root->data)
            {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
            }
        }
    }
    return 0;
}
int main(){
    Node* root = newNode('+');
    root->left = newNode('*');
    root->left->left = newNode((char)5);
    root->left->right = newNode((char)4);
    root->right = newNode('-');
    root->right->left = newNode((char)100);
    root->right->right = newNode('/');
    root->right->right->left = newNode((char)20);
    root->right->right->right = newNode((char)2);
    cout<<solve(root)<<endl;
}