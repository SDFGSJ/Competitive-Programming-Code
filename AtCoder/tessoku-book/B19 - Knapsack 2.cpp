#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
pair<int,int> a[105];   //<weight, value>
long long dp[105][100010];
int main(){
    int n,W,vsum=0;
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
        vsum+=a[i].second;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=vsum;j++){
            dp[i][j]=inf;
        }
    }

    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=vsum;j++){
            dp[i][j]=dp[i-1][j];
            if(j-a[i].second>=0){
                dp[i][j]=min(dp[i][j], dp[i-1][j-a[i].second]+a[i].first);
            }
        }
    }

    int ans=0;
    for(int i=0;i<=vsum;i++){
        if(dp[n][i]<=W){
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
dp[i][j] = min weight of bag when considering item 1-i with total value = j
*/