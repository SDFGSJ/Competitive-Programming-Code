#include<bits/stdc++.h>
using namespace std;
int h[100010],dp[100010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=0;i<n;i++){
        dp[i]=1e9;
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]=min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
            }
        }
    }
    printf("%d\n",dp[n-1]);
    return 0;
}