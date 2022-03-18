#include<iostream>
using namespace std;
bool adj[100][100];
string r = "";
bool findPath(string s, int v){
    r += v+'0';
    for(int i=1; i<s.length(); i++){
        if(adj[v][s[i]-'A'] || adj[s[i]-'A'][v])
            v = s[i]-'A';
        else if(adj[v][s[i]-'A'+5] || adj[s[i]-'A'+5][v])
            v = s[i]-'A'+5;
        else
            return false;
        r += v+'0';
    }
    return true;
}
int main(){
    adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] = adj[4][0] = adj[0][5] = true;
    adj[1][6] = adj[2][7] = adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] = true;
    adj[9][6] = adj[6][8] = adj[8][5] = true;
    string s = "ABB";
    if(findPath(s, s[0]-'A') || findPath(s, s[0]-'A'+5))
        cout<<r;
    else    
        cout<<-1;
}