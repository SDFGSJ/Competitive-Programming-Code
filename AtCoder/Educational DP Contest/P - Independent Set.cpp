#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<int> Tree[100010];
int dp[100010][2];
int dfs(int u,int pick,int parent = -1){
    if(dp[u][pick]){
        return dp[u][pick];
    }

    long long result=1;
    for(auto v:Tree[u]){
        if(v!=parent){
            if(pick==0){
                result*=1ll*(dfs(v,0,u)+dfs(v,1,u));
            }else{
                result*=1ll*dfs(v,0,u);
            }
            result%=mod;
        }
    }
    dp[u][pick]=result;
    return dp[u][pick];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Tree[x].emplace_back(y);
        Tree[y].emplace_back(x);
    }

    long long ans=(dfs(1,0)+dfs(1,1))%mod;
    printf("%lld\n",ans);
}
/*
v = u's children
dp[u][0]
= #ways to paint subtree rooted at u when node u is not chosen
= £S(dp[v][0]+dp[v][1])

dp[u][1]
= #ways to paint subtree rooted at u when node u is chosen
= £S(dp[v][0])
*/