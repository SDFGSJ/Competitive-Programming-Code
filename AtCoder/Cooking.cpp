#include<bits/stdc++.h>
using namespace std;
int t[1010];
bool dp[105][100010];
int main(){
    int n,total=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        total+=t[i];
    }

    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100000;j++){
            dp[i][j]=dp[i-1][j];
            if(j-t[i]>=0){
                dp[i][j]|=dp[i-1][j-t[i]];
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<=100000;i++){
        if(dp[n][i]){
            ans=min(ans, max(i, total-i));
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
dp[i][j] = true if from 1 to n, we can have sum=j
init dp[0][0] = true
dp[i][j] = dp[i-1][j], if dont choose t[i]
dp[i][j] = dp[i-1][j] | dp[i-1][j-t[i]], if choose t[i]
*/