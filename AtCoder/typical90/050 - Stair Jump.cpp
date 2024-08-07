#include<bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int dp[200010];
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=0;i<=l-1;i++){
        dp[i]=1;
    }
    for(int i=l;i<=n;i++){
        dp[i]=max(dp[i], dp[i-1]+dp[i-l])%mod;
    }
    printf("%d\n",dp[n]);
    return 0;
}