#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char grid[1005][1005];
long long dp[1005][1005];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
    }

    for(int i=0;i<h && grid[i][0]!='#';i++){
        dp[i][0]=1;
    }
    for(int i=0;i<w && grid[0][i]!='#';i++){
        dp[0][i]=1;
    }

    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(grid[i][j]!='#'){
                dp[i][j]=max(dp[i][j], dp[i-1][j]+dp[i][j-1]);
                dp[i][j]%=mod;
            }
        }
    }
    printf("%lld\n",dp[h-1][w-1]);
    return 0;
}
/*
dp[i][j] = #ways to reach (i,j) (0-indexed)
*/