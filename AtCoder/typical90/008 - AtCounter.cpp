#include<bits/stdc++.h>
using namespace std;
char str[100010];
int dp[100010][10];
const int mod=1e9+7;
const string words = ".atcoder";
int main(){
    int n;
    scanf("%d%s",&n,str+1);

    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=7;j++){
            if(str[i]==words[j]){
                dp[i][j]=(dp[i-1][j-1] + dp[i-1][j])%mod;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("%d\n",dp[n][7]);
    return 0;
}
/*
s, "atcoder" are 1-indexed
dp[i][j] = #ways to produce "atcoder"[1-j] from s[1-i]
*/