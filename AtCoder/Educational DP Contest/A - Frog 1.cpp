#include<bits/stdc++.h>
using namespace std;
int h[100010],dp[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    dp[1]=0;dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(h[i] - h[i-1]), dp[i-2]+abs(h[i] - h[i-2]));
    }
    printf("%d\n",dp[n]);
    return 0;
}
/*
dp[i]=min cost to get on stone i
*/