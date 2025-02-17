#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
int color[200010];
bool dfs(int u,int c){
    if(color[u]){
        return color[u]==c;
    }
    color[u]=c;
    for(auto v:G[u]){
        if(!dfs(v,c*-1)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    bool is_bipartitie=dfs(1,1);
    if(!is_bipartitie){
        printf("0\n");
        return 0;
    }
    int black=0,white=0;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            white++;
        }else{
            black++;
        }
    }

    //printf("black=%d, white=%d, cross=%d\n",black,white,m);
    printf("%lld\n",1ll*black*white-m);
    return 0;
}
/*
if input graph is not bipartite, then no
mark every note in 0,1
find how many edges can be added between 0,1
*/