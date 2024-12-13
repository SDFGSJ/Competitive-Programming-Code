#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> G[200010],rG[200010];    //<v,w>
bool visited[200010];
long long ans[200010];
void bfs(int start){
    queue<int> q; //<v,w>
    q.emplace(start);
    ans[start]=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto [v,weight]:G[u]){
            ans[v]=ans[u]+weight;
            q.emplace(v);
        }
        for(auto [v,weight]:rG[u]){
            ans[v]=ans[u]+weight;
            q.emplace(v);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].emplace_back(v,w);
        rG[v].emplace_back(u,-w);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
        }
    }

    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
u->v with weight w and xv-xu=w
=> xv=xu+w and xu=xv-w
so we maintain 2 graphs, one stores (u,v,w) edges, the other stores (v,u,-w) edges

Note.
editorial store 2 edges (u,v,w), (v,u,-w) in one graph instead of 2
*/