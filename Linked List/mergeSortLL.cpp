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
Node* merge(Node* a, Node* b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node* res;
    if(a->data<b->data){
        res = a;
        res->next = merge(a->next, b);
    }
    else{
        res = b;
        res->next = merge(a, b->next);
    }
    return res;
}
Node* findMid(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSort(Node* head){
    Node* ptr = head;
    cout<<"LL:";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
    if(head==NULL || head->next==NULL)
        return head;
    Node* mid = findMid(head);
    if(mid!=NULL)
        cout<<"Mid:"<<mid->data<<endl;
    Node* p = head;
    while(p->next!=mid)
        p = p->next;
    p->next = NULL;
    Node* l = mergeSort(head);
    Node* r = mergeSort(mid);
    Node* res = merge(l, r);
    cout<<"Left:";
    while(l!=NULL){
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<endl;
    cout<<"Right:";
    while(r!=NULL){
        cout<<r->data<<" ";
        r = r->next;
    }
    cout<<endl;
    cout<<"==========================="<<endl;
    return res;
}
int main(){
    Node* head = newNode(3);
    head->next = newNode(5);
    head->next->next = newNode(2);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(1);
    Node* res = mergeSort(head);
    while(res!=NULL){
        cout<<res->data<<" ";
        res = res->next;
    }
}