#include<bits/stdc++.h>
using namespace std;
int dp[100010][3];
int main(){
    int n;
    scanf("%d",&n);
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    dp[0][0]=a,dp[0][1]=b,dp[0][2]=c;
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        dp[i][0]=max({dp[i][0], dp[i-1][1]+a, dp[i-1][2]+a});
        dp[i][1]=max({dp[i][1], dp[i-1][0]+b, dp[i-1][2]+b});
        dp[i][2]=max({dp[i][2], dp[i-1][0]+c, dp[i-1][1]+c});
    }
    printf("%d\n",max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));
    return 0;
}
/*
dp[i][0] = max happiness when doing activity a on day i
dp[i][1] = max happiness when doing activity b on day i
dp[i][2] = max happiness when doing activity c on day i
*/