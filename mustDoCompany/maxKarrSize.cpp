#include<bits/stdc++.h>
using namespace std;
vector<int> maxSub(int a[], int n, int k){
    vector<int> res;
    int i=0, j=0;
    priority_queue<pair<int, int>> pq;
    while(j<n){
        pq.push({a[j], j});
        if(j-i+1 < k)
            j++;
        else{
            while(!pq.empty() && pq.top().second<i)
                pq.pop();
            res.push_back(pq.top().first);
            i++, j++;
        }
    }
    return res;
}
int main(){
    int a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> v = maxSub(a, 9, 3);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}