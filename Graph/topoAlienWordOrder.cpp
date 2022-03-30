#include<iostream>
using namespace std;
vector<int> adj[100];
void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void topoSortUtil(int v, vector<bool>& visited, stack<int>& s){
    visited[v] = true;
    for(int i : adj[v])
        if(!visited[i])
            topoSort(i, visited, s);
    s.push(v);
}
void toposort(int c){
    stack<int> s;
    vector<bool> visited(c, false);
    for(int i=0; i<c; i++)
        if(!visited[i])
            topoSortUtil(i, visited, stack);
    while(!s.empty()){
        cout<<(char)('a'+s.top())<<" ";
        s.pop();
    }
}
void alienOrder(vector<string> words, int c, int n){
    for(int i=0; i<n-1; i++){
        string w1 = words[i], w2 = words[i+1];
        for(int j=0; j<min(w1.length(), w2.length()); j++){
            if(w1[j]!=w2[j]){
                addEdge(w1[j], w2[j]);
                break;
            }
        }
    }
    topoSort(c);
}
int main(){
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    alienOrder(words, 4, 5);
}