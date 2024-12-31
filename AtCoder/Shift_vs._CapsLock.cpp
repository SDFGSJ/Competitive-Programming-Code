#include<bits/stdc++.h>
using namespace std;
char s[300010];
long long dp[300010][2];
int main(){
    int x,y,z;
    scanf("%d%d%d%s",&x,&y,&z,s+1);
    int n=strlen(s+1);

    for(int i=1;s[i]!='\0';i++){
        dp[i][0]=dp[i][1]=LONG_LONG_MAX;
    }

    dp[0][0]=0,dp[0][1]=z;
    for(int i=1;s[i]!='\0';i++){
        if(s[i]=='a'){
            dp[i][0]=min({dp[i-1][0]+x, dp[i-1][1]+z+x, dp[i-1][1]+y+z});
            dp[i][1]=min({dp[i-1][1]+y, dp[i-1][0]+z+y, dp[i-1][0]+x+z});
        }else{
            dp[i][0]=min({dp[i-1][0]+y, dp[i-1][1]+x+z, dp[i-1][1]+z+y});
            dp[i][1]=min({dp[i-1][1]+x, dp[i-1][0]+y+z, dp[i-1][0]+z+x});
        }
    }
    printf("%lld\n",min(dp[n][0], dp[n][1]));
    return 0;
}
/*
FSM DP
state 0/1 = Caps Lock off/on
dp[i][0/1] = min cost to type str[1..i] and Caps Lock is off/on after finish typing str[i]
draw FSM
dp[i][0] = min(
    press 'a' on state 0 (start from state 0, end at 0)
    transition from state 1 to 0 then press 'a' (start from state 1, end at 0)
    press shift+'a' on state 1 then transit from state 1 to 0 (start from state 1, end at 0)
)
similar recurrence for dp[i][1]
the ans is min(dp[n][0], dp[n][1])
*/