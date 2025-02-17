#include<bits/stdc++.h>
using namespace std;
vector<int> T[200010];
long long t[200010],ans[200010];
bool vis[200010];
long long dfs(int u){
    if(vis[u]){
        return 0;
    }

    long long branch_sum=0;
    for(auto v:T[u]){
        branch_sum+=dfs(v);
    }

    ans[u]=t[u]+branch_sum;
    vis[u]=true;    //mark u as finish calculating ans
    return ans[u];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%lld%d",&t[i],&k);
        for(int j=0;j<k;j++){
            int a;
            scanf("%d",&a);
            T[i].emplace_back(a);
        }
    }

    long long ans=dfs(n);
    printf("%lld\n",ans);
    return 0;
}
/*
store the reversed graph and use dfs to find topo order
use vis[] to avoid re-calculation
*/