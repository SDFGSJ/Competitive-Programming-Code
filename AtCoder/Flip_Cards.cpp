#include<bits/stdc++.h>
using namespace std;
int front[200010],back[200010];
int dp[200010][2];
const int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&front[i],&back[i]);
    }

    dp[1][0]=1;dp[1][1]=1;
    for(int i=2;i<=n;i++){
        if(front[i]!=front[i-1]){   //front side of card i is different from that of card i-1
            dp[i][0]+=dp[i-1][0];
        }
        if(front[i]!=back[i-1]){    //front side of card i is different from the back side of card i-1
            dp[i][0]+=dp[i-1][1];
        }
        dp[i][0]%=mod;

        if(back[i]!=front[i-1]){
            dp[i][1]+=dp[i-1][0];
        }
        if(back[i]!=back[i-1]){
            dp[i][1]+=dp[i-1][1];
        }
        dp[i][1]%=mod;
    }
    printf("%d\n",(dp[n][0]+dp[n][1])%mod);
    return 0;
}
/*
dp[i][0/1] = # of ways to flip the cards from 1 to i, and the front/back side of the i-th card is facing up
*/