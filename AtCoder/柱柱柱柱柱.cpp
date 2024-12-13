#include<bits/stdc++.h>
using namespace std;
int h[100010],dp[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        dp[i]=INT_MAX;
    }

    dp[0]=0;
    for(int i=1;i<n;i++){
        if(i-1>=0){
            dp[i]=min(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        }
        if(i-2>=0){
            dp[i]=min(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
        }
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
/*
dp[i] = min cost from 0 to i
*/