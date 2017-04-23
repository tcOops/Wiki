#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using namespace std;
const int maxn = 106;
int dp[maxn][maxn][maxn];
const int inf = 1e8;
string s;
int solve(int l,int r,int d){
    if(l>r)return 0;
    if(s[l]-'A'==d&&l==r)return dp[l][r][d]=0;
    if(l==r)return dp[l][r][d]=1;
    if(dp[l][r][d]!=-1)return dp[l][r][d];
    dp[l][r][d]=inf;
    for(int i=0;i<26;i++){
        dp[l][r][d]=min(dp[l][r][d],solve(l,r,i)+1);
    }
    if(s[l]-'A'==d)dp[l][r][d]=min(dp[l][r][d],solve(l+1,r,d));
    if(s[r]-'A'==d)dp[l][r][d]=min(dp[l][r][d],solve(l,r-1,d));
    for(int i=l+1;i<r;i++){
        if(s[i]-'A'==d){
            dp[l][r][d]=min(dp[l][r][d],solve(l,i-1,d)+solve(i+1,r,d));
        }
    }
    return dp[l][r][d];
}
int main(){
    while(cin>>s){
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,s.size()-1,27)<<endl;
    }
}

