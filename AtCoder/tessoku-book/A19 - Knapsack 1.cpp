#include<bits/stdc++.h>
using namespace std;
int w[105],v[105];
long long dp[105][100010];
int main(){
    int n,W;
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=dp[i-1][j];
            if(j-w[i]>=0){
                dp[i][j]=max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%lld\n",dp[n][W]);
    return 0;
}