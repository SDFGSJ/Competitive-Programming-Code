#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> G;
map<int,bool> visited;
int ans=1;
void dfs(int u){
    if(visited[u]){
        return;
    }
    visited[u]=true;
    for(auto v:G[u]){
        ans=max(ans,v);
        dfs(v);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}