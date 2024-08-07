//solve after reading editorial
#include<bits/stdc++.h>
using namespace std;
double p[3010],dp[3010][3010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&p[i]);
    }

    dp[0][0]=1;
    for(int i=1;i<=n;i++){  //until coin i
        for(int j=0;j<=i;j++){  //at most i heads
            if(j>0){
                dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
            }else{
                dp[i][j]=dp[i-1][j]*(1-p[i]);
            }
        }
    }

    double ans=0.0;
    for(int i=0;i<=n;i++){
        if(i>n-i){  //#heads > #tails
            ans+=dp[n][i];
        }
    }
    printf("%.10f\n",ans);
    return 0;
}
/*
dp[i][j] = #heads thrown until coin i
*/