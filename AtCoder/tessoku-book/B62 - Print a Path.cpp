#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int prede[100010];
bool visited[100010];
void dfs(int u){
    if(visited[u]){
        return;
    }
    visited[u]=true;
    for(auto v:G[u]){
        if(prede[v]==0){
            prede[v]=u;
        }
        dfs(v);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    prede[1]=1;
    dfs(1);

    vector<int> path;
    path.emplace_back(n);
    while(prede[n]!=n){
        path.emplace_back(prede[n]);
        n=prede[n];
    }
    reverse(path.begin(),path.end());
    for(auto node:path){
        printf("%d ",node);
    }
    printf("\n");
    return 0;
}