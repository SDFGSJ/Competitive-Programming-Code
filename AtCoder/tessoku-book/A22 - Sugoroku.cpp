#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],dp[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n-1;i++){
        scanf("%d",&b[i]);
    }

    for(int i=1;i<=n;i++){
        dp[i]=-1e9;
    }

    dp[1]=0;
    for(int i=1;i<=n-1;i++){    //now on block i
        dp[a[i]]=max(dp[a[i]], dp[i]+100);
        dp[b[i]]=max(dp[b[i]], dp[i]+150);
    }
    printf("%d\n",dp[n]);
    return 0;
}