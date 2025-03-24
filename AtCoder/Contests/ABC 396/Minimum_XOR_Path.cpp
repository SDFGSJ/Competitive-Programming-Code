#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> G[15];  //<v,w>
bool vis[15];
long long ans=LONG_LONG_MAX;
void dfs(int u,int par,long long cost,int goal){
    if(vis[u]){
        return;
    }
    if(u==goal){    //has reached vertex n
        ans=min(ans,cost);
    }
    vis[u]=true;
    for(auto [v,w]:G[u]){
        if(v!=par){
            dfs(v,u,cost^w,goal);
        }
    }
    vis[u]=false;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    dfs(1,-1,0,n);
    printf("%lld\n",ans);
    return 0;
}
/*
brute force dfs
*/