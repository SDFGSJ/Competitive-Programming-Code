#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int dp[100010][3];
/*
dp[i][0]=the max total points of happiness of the first i days & choose "a" on day i
dp[i][1]=the max total points of happiness of the first i days & choose "b" on day i
dp[i][2]=the max total points of happiness of the first i days & choose "c" on day i
*/
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }

    for(i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];  //max(previous day do b,c) + a[i]
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];  //max(previous day do a,c) + b[i]
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];  //max(previous day do a,b) + c[i]
    }
    printf("%d",max({dp[n][0], dp[n][1], dp[n][2]}));   //max is the answer
    return 0;
}