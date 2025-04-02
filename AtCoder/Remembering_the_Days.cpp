#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> G[15];    //<v,cost>
int ans=-1;
void dfs(int u,int parent,int vismask,int cost){
    if(vismask&(1<<u)){
        return;
    }
    ans=max(ans,cost);
    for(auto [v,c]:G[u]){
        if(v!=parent){
            dfs(v,u,vismask^(1<<u),cost+c);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }

    for(int i=1;i<=n;i++){
        dfs(i,-1,0,0);
    }
    printf("%d\n",ans);
    return 0;
}
/*
dfs brute force
*/