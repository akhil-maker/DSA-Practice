// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
char flip(char ch){
    return (ch == 'L') ? 'L' : 'R';
}

int getFlip(string str, char expected){
    int flipCount = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] != expected)
            flipCount++;
        expected = flip(expected);
    }
    return flipCount;
}
 
int minFlip(string str){
    return min(getFlip(str, 'L'), getFlip(str, 'R'));
}
int maxScore(vector<int>& nums, int rounds) {
        int n = nums.size() >> 1;
        int total = (n << 1);
        int32_t dp[rounds + 1][1 << total];
        memset(dp, 0, sizeof dp);
        int32_t gcd[total][total];
        for (int i = 0; i < total; ++i) {
            for (int j = i + 1; j < total; ++j) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        for (int round = 1; round <= rounds; ++round) {
            for (int mask = 0; mask < (1 << total); ++mask) {
                if (__builtin_popcount(mask) == (round << 1)) {
                    for (int i = 0; i < total; ++i) {
                        if (mask & (1 << i)) {
                            for (int j = i + 1; j < total; ++j) {
                                if (mask & (1 << j)) {
                                    dp[round][mask] = max(dp[round][mask], dp[round - 1][mask ^ (1 << i) ^ (1 << j)] + gcd[i][j] * round);
                                }
                            }   
                        }
                    }
                }
            }
        }
        return dp[rounds][(1 << total) - 1];
}

int main(){
    string str = "LLLRRR";
   cout << minFlip(str);
   vector<int> a= {3, 4, 9, 5};
   cout<<maxScore(a, 2);
}

  // } Driver Code Ends
// #include<bits/stdc++.h>
// using namespace std;

// vector<pair<long long int,long long int>> a[100000];
// vector<bool> visited(100000,0);
// long long int mn=999999999999999,res=0,k=mn;
// void dfs(long long int u,long long int v)
// {
// if(u==v)
// {
// if(mn>res)
// {
// mn=res;
// }
// }
// visited[u]=1;
// for(auto j: a[u])
// {
// if(visited[j.first]==0)
// {
// res+=j.second;
// visited[j.first]==1;
// dfs(j.first,v);
// visited[j.first]==0;
// res-=j.second;
// }
// }
// visited[u]=0;
// }
// int main()
// {
// /* Enter your code here. Read input from STDIN. Print output to STDOUT */
// long long int n,e,x,y,i,w;
// cin>>n;
// for(i=0;i<n;i++)
// {
// cin>>x;
// }
// cin>>e;
// for(i=0;i<e;i++)
// {
// cin>>x>>y>>w;
// a[x].push_back({y,w});
// }
// cin>>x>>y;
// dfs(x,y);
// if(mn==k)
// cout<<"-1";
// else
// cout<<mn;
// return 0;
// }

// #include<iostream>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
// };
// Node* newNode(int data){
//     Node* p = new Node;
//     p->data = data;
//     p->next = NULL;
//     return p;
// }
// Node* remoLoop(Node* head){
//     Node* slow = head, *fast = head;
//     slow = head->next, fast = head->next->next;
//     while(fast && fast->next){
//         if(slow==fast)
//             break;
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     if(slow==fast){
//         slow = head;
//         if(slow==fast)
//             while(fast->next!=slow) fast = fast->next;
//         else{
//             while(slow->next!=fast->next){
//                 slow = slow->next;
//                 fast = fast->next;
//             }
//             fast->next = NULL;
//         }
//     }
//     return head;
// }
// Node* endNode(Node* head, int n){
//     Node* slow = head, *fast = head;
//     for(int i=0; i<n; i++){
//         if(fast==NULL)
//             return head;
//         fast = fast->next;
//     }
//     while(fast!=NULL && fast->next!=NULL){
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return slow;
// }
// void computeLPS(string p, int m, int* lps){
//     int len = 0;
//     lps[0] = 0;
//     int i = 1;
//     while(i<m){
//         if(p[i]==p[len]){
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else{
//             if(len!=0)
//                 len = lps[len-1];
//             else{
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
// }
// void KMPSearch(string p, string t){
//     int m = p.length(), n = t.length();
//     int lps[m];
//     computeLPS(p, m, lps);
//     int i = 0, j = 0;
//     while(i<n){
//         if(p[j]==t[i])
//             i++, j++;
//         if(j==m){
//             cout<<"Found pattern at "<<i-j<<endl;
//             j = lps[j-1];
//         }
//         else if(i<n && p[j]!=t[i]){
//             if(j!=0) j = lps[j-1];
//             else i++;
//         }
//     }
// }
// void zigzag(Node* head){
//     bool flag = true; /* expected < */
//     Node* curr = head;
//     while(curr->next!=NULL){
//         if(flag){
//             if(curr->data>curr->next->data)
//                 swap(curr->data, curr->next->data);
//         }
//         else{
//             if(curr->data<curr->next->data)
//                 swap(curr->data, curr->next->data);
//         }
//         flag = !flag;
//         curr = curr->next;
//     }
// }
// int m[1001][1001];
// int getElementMore(int num, int n){
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         if(m[i][0]>num)
//             return ans;
//         if(m[i][n-1]<=num){
//             ans += n;
//             continue;
//         }
//         int gre = 0;
//         for(int jump=n/2; jump>=1; jump/=2){
//             while(gre+jump<n && m[i][gre+jump]>=num)
//                 gre += jump;
//         }
//         ans += gre+1;
//     }
//     return ans;
// }
// int kthSmallest(int n, int k){
//     int l = m[0][0], r = m[n-1][n-1];
//     while(l<=r){
//         int mid = l + (r-l)/2;
//         int gremid = getElementMore(mid, n);
//         if(gremid<=k)
//             r = mid-1;
//         else
//             l = mid+1;
//     }
//     return l;
// }
// int sumPrime(int l, int r){
//     int prime[r+1] = {0};
//     for(int i=2; i*i<=r; i++){
//         if(prime[i]==true){
//             for(int j=i*i; j<=r; j+=i)
//                 prime[j] = false;
//         }
//     }
//     int sum = 0;
//     for(int p=l; p<=r; p++)
//         if(prime[p])
//             sum += p;
//     return sum;
// }
// void maxmax2(int a[], int n){
//     int first = a[0], second = a[0];
//     for(int i=1; i<n; i++){
//         if(a[i]>first){
//             second = first;
//             first = a[i];
//         }
//         else if(second<a[i] && a[i]<first)
//             second = a[i];
//     }
//     cout<<first<<" "<<second<<endl;
// }
// void polyproduct(int a[], int b[], int m, int n){
//     int *p = new int[m+n-1];
//     for(int i=0; i<m; i++)
//         for(int j=0; j<n; j++)
//             p[i+j] += a[i]*b[j];
//     for(int i=0; i<m+n-1; i++){
//         cout<<p[i];
//         if(i!=0) cout<<"x^"<<i;
//         if(i!=n-1) cout<<" + ";
//     }
//     cout<<endl;
// }

// int main(){
//     Node* h = newNode(4);
//     h->next = newNode(3);
//     h->next->next = newNode(7);
//     h->next->next->next = newNode(8);
//     h->next->next->next->next = newNode(6);
//     h->next->next->next->next->next = newNode(2);
//     h->next->next->next->next->next->next = newNode(1);
//     zigzag(h);
//     while(h!=NULL){
//         cout<<h->data<<" ";
//         h = h->next;
//     }
//     int n;
//     cin>>n;
//     for(int i=0; i<n; i++)
//         for(int j=0; j<n; j++)
//             cin>>m[i][j];
//     cout<<kthSmallest(n, 3);
// }