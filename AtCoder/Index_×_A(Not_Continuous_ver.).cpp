#include<bits/stdc++.h>
using namespace std;
int a[2010];
long long dp[2010][2010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=LONG_LONG_MIN;
        }
    }

    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=i;j<=n;j++){
            dp[i][j]=max(dp[i][j-1], dp[i-1][j-1]+a[j]*i);
        }
    }

    long long ans=LONG_LONG_MIN;
    for(int i=m;i<=n;i++){
        ans=max(ans,dp[m][i]);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
dp[i][j] = max score of seq with len = i in a[1~j]
dp[i][j-1]: dont choose a[j] => take seq of length i with max score from a[1-j]
dp[i-1][j-1]+a[j]*i: choose a[j] as the i-th term => take seq of length i-1 from a[1-(j-1)]
*/