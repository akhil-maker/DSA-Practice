#include<iostream>
using namespace std;
int dp[1001][1001];
bool isPalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j])
            return false;
        i++, j--;
    }
    return true;
}
int palPart(string s, int i, int j){
    if(i>=j)
        return 0;
    if(isPalindrome(s, i, j))
        return 0;
    int tempans, ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        tempans = palPart(s, i, k)+palPart(s, k+1, j)+1;
        ans = min(tempans, ans);
    }
    return ans;
}
int palPartMemo(string s, int i, int j){
    if(i>=j)
        return dp[i][j]=0;
    if(isPalindrome(s, i, j))
        dp[i][j] = 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int tempans, ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        tempans = palPart(s, i, k)+palPart(s, k+1, j)+1;
        ans = min(tempans, ans);
    }
    return dp[i][j]=ans;
}
int palPartMemoOpt(string s, int i, int j){
    if(i>=j)
        return 0;
    if(isPalindrome(s, i, j))
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp = 1+(dp[i][k]!=-1)?dp[i][k]:palPartMemoOpt(s, i, k)+(dp[k+1][j]!=-1)?dp[k+1][j]:palPartMemoOpt(s, k+1, j);
        mn = min(mn, temp);
    }
    return dp[i][j]=mn;
}
int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++)
        for(int j=0; j<s.length(); j++)
            dp[i][j] = -1;
    cout<<palPart(s, 0, s.length()-1)<<endl;
    cout<<palPartMemo(s, 0, s.length()-1)<<endl;
    cout<<palPartMemoOpt(s, 0, s.length()-1)<<endl;
}
