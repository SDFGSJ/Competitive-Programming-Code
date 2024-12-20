#include<bits/stdc++.h>
using namespace std;
int dp[1000010][15];
const int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=9;j++){
            dp[i][j]=(1ll*dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        }
    }

    int ans=0;
    for(int i=1;i<=9;i++){
        ans=(ans+dp[n][i])%mod;
    }
    printf("%d\n",ans);
    return 0;
}
/*
dp[i][j] = # of ways to make a str with len i which ends with digit j
=> dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
make sure that 1 <= j-1,j,j+1 <= 9
*/