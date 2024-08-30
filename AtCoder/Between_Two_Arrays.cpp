#include<bits/stdc++.h>
using namespace std;
int dp[3010][3010],a[3010],b[3010];
const int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }

    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=b[i];j++){    //copy from previous row
            dp[i][j]=dp[i-1][j];
        }
        for(int j=1;j<=3000;j++){   //do prefix sum
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    printf("%d\n",dp[n][3000]);
    return 0;
}
/*
dp[i][j] = #ways to produce "seq of len i whose last element = j"
dp[i][j] = sum(dp[i-1][k]), k = 0 ~ j => use preifx sum
ex. a[]={1,2,3}, b[]={3,4,5}
dp[0] 100000
dp[1] 011100
dp[2] 002330
dp[3] 000588
ans=5+8+8=21
*/