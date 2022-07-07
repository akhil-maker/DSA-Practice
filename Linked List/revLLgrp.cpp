#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int data){
    Node* p = new Node;
    p->data = data;
    p->next = NULL;
    return p;
}
Node* getListAfterReverseOperation(Node *head, int n, int b[], int ind){
	// Write your code here.
    if(ind==n)
        return head;
    int k = b[ind], cnt = 0;
    Node* prev = NULL, *curr = head, *ne = NULL;
    while(curr!=NULL && cnt<k){
        ne = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ne;
        cnt++;
    }
    if(ne!=NULL)
        head->next = getListAfterReverseOperation(ne, n, b, ind+1);
    head = prev;
    return head;
}
int main(){
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    // head->next->next->next->next->next = newNode(6);
    // head->next->next->next->next->next->next = newNode(7);
    // head->next->next->next->next->next->next->next = newNode(8);
    // head->next->next->next->next->next->next->next->next = newNode(9);
    // head->next->next->next->next->next->next->next->next->next = newNode(10);
    // head->next->next->next->next->next->next->next->next->next->next = newNode(11);
    int b[] = {3, 3, 5};
    Node* p = getListAfterReverseOperation(head, 3, b, 0);
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}