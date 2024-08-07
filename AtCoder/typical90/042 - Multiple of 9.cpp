#include<bits/stdc++.h>
using namespace std;
int dp[100010];
const int mod=1e9+7;
int main(){
    int k;
    scanf("%d",&k);

    if(k%9!=0){
        printf("0\n");
    }else{
        dp[0]=1;
        for(int i=1;i<=k;i++){
            int msb=min(i,9);
            for(int j=1;j<=msb;j++){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
        printf("%d\n",dp[k]);
    }
    return 0;
}
/*
dp[i] = #ways when digit sum is i

k=12
msb = 1 => 1__ => dp[11]
msb = 2 => 2__ => dp[10]
...
msb = 9 => 9__ => dp[3]
dp[12] = dp[11] + dp[10] + ... + dp[3]
*/