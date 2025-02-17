#include<bits/stdc++.h>
using namespace std;
int A[10010],B[10010],dp[10010];
int main(){
    int H,n;
    scanf("%d%d",&H,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&A[i],&B[i]);
    }

    for(int i=0;i<=H;i++){
        dp[i]=1e9;
    }

    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=H-1;j++){
            if(j+A[i]<=H){
                dp[j+A[i]]=min(dp[j+A[i]], dp[j]+B[i]);
            }else{
                dp[H]=min(dp[H], dp[j]+B[i]);
            }
        }
    }
    printf("%d\n",dp[H]);
    return 0;
}
/*
dp
dp[i] = min magic point to decrease monster's health by i
if j+A[i]>=H, which means we cause a damage >=H
then we update dp[H] instead of dp[j+A[i]]
since a spell can be casted multiple times, so we update dp[] in asc order(j=0~H-1)
*/