#include<bits/stdc++.h>
using namespace std;
int dp[2010];
const int mod=1e9+7;
int main(){
    int s;
    scanf("%d",&s);

    dp[0]=1;
    for(int i=3;i<=s;i++){  //seq sum=i
        for(int j=3;j<=s;j++){  //MSB
            if(i-j>=0){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
    }
    printf("%d\n",dp[s]);
    return 0;
}
/*
dp[i] = #seq that has sum=i
3__ => dp[i-3]
4__ => dp[i-4]
...
i__ => dp[0]
note that the MSB should >= 3, so >9 is also ok
*/