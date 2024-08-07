#include<bits/stdc++.h>
using namespace std;
long long dp[500010][2];
int a[500010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+a[i];
    }
    printf("%lld\n",max(dp[n][0], dp[n][1]));
    return 0;
}