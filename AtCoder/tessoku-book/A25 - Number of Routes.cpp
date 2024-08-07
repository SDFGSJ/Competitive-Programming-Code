#include<bits/stdc++.h>
using namespace std;
char grid[35][35];
long long dp[35][35];
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

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]!='#'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    printf("%lld\n",dp[h-1][w-1]);
    return 0;
}