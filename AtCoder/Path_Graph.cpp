#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
int deg[200010];
bool visited[200010];
void dfs(int u){
    if(visited[u]){
        return;
    }
    visited[u]=true;
    for(auto v:G[u]){
        dfs(v);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        deg[u]++,deg[v]++;
    }

    int compo=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            compo++;
            dfs(i);
        }
    }

    int ones=0,twos=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            ones++;
        }else if(deg[i]==2){
            twos++;
        }
    }
    if(compo==1 && ones==2 && twos==n-2){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}