#include<bits/stdc++.h>
using namespace std;
int x[100010];
long long dp[100010];
int main(){
    int n;
    long long a,b;
    scanf("%d%lld%lld",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        if(i==1){
            dp[1]=0;
        }else{
            dp[i]=dp[i-1]+min(a*(x[i]-x[i-1]), b);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
/*
dp[i] = min fatigue level when travelling from 1 to i
it is always better to travel in asc order 1,2,3,...n
*/