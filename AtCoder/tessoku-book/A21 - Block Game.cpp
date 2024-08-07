#include<bits/stdc++.h>
using namespace std;
int p[2010],a[2010],dp[2010][2010];
int dfs(int l,int r){
    //printf("(%d,%d)\n",l,r);
    if(dp[l][r]){
        return dp[l][r];
    }
    if(l==r){
        return 0;
    }

    dp[l][r]=max(dfs(l+1,r)+(r==p[l]?a[l]:0), dfs(l,r-1)+(l==p[r]?a[r]:0));
    return dp[l][r];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i],&a[i]);
    }
    printf("%d\n",dfs(1,n));
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}