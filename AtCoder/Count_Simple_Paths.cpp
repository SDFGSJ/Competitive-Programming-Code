#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
bool vis[200010];
int ans;
void dfs(int u,int pre){
    if(vis[u]){
        return;
    }

    //if we find 1e6 paths until now, the ans could only be 1e6
    //so no need to expand further
    //ans++ should be placed after the if branch
    //otherwise it will fail on cases that have >=1e6 paths
    if(ans>=1000000){
        return;
    }
    ans++;

    vis[u]=true;
    for(auto v:G[u]){
        if(v!=pre){
            dfs(v,u);
        }
    }
    vis[u]=false;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d,",&u,&v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1,-1);
    printf("%d\n",ans);
    return 0;
}
/*
dfs + pruning
*/