#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[55][2505];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    dp[0][0]=1;
    for(int i=1;i<=n;i++){  //i-th element
        for(int j=1;j<=k;j++){  //sum = j
            for(int Ai=1;Ai<=m;Ai++){   //the value of i-th element
                if(j-Ai>=0){
                    dp[i][j]+=dp[i-1][j-Ai];
                    dp[i][j]%=mod;
                }
            }
        }
    }

    long long ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+dp[n][i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
dp[i][S] = # of ways to make the sum of the first i elements = S
*/