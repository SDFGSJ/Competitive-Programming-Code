#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long dp[200010][2];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    dp[1][0]=0,dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0], dp[i-1][1]+a[i]*2);
        dp[i][1]=max(dp[i-1][1], dp[i-1][0]+a[i]);
    }
    printf("%lld\n",max(dp[n][0], dp[n][1]));
    return 0;
}
/*
dp[i][0/1] = max exp from monsters 1~i and you have defeated even/odd monsters
= max(dont defeat i-th monster, defeat i-th monster)
*/