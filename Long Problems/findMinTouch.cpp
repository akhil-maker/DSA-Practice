#include<iostream>
using namespace std;
int n, m, o;
int *working, *operation;
int ans = INT_MAX;
int eval(int prev, int curr, int op){
    if(prev==-10000000) return curr;
    if(op==1) return prev+curr;
    if(op==2) return prev-curr;
    if(op==3) return prev*curr;
    if(op==4){
        if(curr==0) return -1;
        else return prev/curr;
    }
    return -1;
}
bool isDone(int prev, int curr, int opr, int t){
    if(opr==4 && curr==0)
        return false;
    if(eval(prev, curr, opr)==t)
        return true;
    return false;
}
void findMinTouch(int prev, int curr, int opr, int tou, int t){
    if(opr!=-1 && curr!=-10000000){
        bool k = isDone(prev, curr, opr, t);
        if(k && tou<o){
            if(ans>tou+1)
                ans = tou+1;
        }
    }
    if(prev==t && tou<o && opr!=-1 && curr==-10000000)
        ans = min(ans, tou);
    if(opr==-1 && curr==t && tou<o)
        ans = min(ans, tou);
    if(tou>o) return;
    for(int i=0; i<m; i++){
        if(curr==-10000000)
            break;
        if(curr==0 && opr==4) continue;
        int val = eval(prev, curr, opr);
        findMinTouch(val, -10000000, operation[i], tou+1, 1);
    }
    for(int i=0; i<n; i++){
        if(curr==-10000000)
            findMinTouch(prev, working[i], opr, tou+1, t);
        else{
            int val = abs(curr);
            val = val*10+working[i];
            if(curr<0) val*=-1;
            findMinTouch(prev, val, opr, tou+1, t);
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        ans = INT_MAX;
        cin>>n>>m>>o;
        working = new int[n+2];
        for(int i=0; i<n; i++)
            cin>>working[i];
        operation = new int[m+2];
        for(int i=0; i<m; i++)
            cin>>working[i];
        int target;
        cin>>target;
        findMinTouch(-10000000, -10000000, -1, 0, target);
        cout<<"#"<<i+1<<": "<<ans<<endl;
    }
}