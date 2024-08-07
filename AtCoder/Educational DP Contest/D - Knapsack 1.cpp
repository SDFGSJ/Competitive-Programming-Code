#include<bits/stdc++.h>
using namespace std;
int weights[105],values[105];
long long dp[105][100010];
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&weights[i],&values[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=dp[i-1][j];    //ignore item i
            if(j-weights[i]>=0){    //choose item i
                dp[i][j]=max(dp[i][j], dp[i-1][j-weights[i]]+values[i]);
            }
        }
    }
    printf("%lld\n",dp[n][w]);
    return 0;
}
/*
dp[i][j] = max value when considering items 1-i with bag capacity=j
*/