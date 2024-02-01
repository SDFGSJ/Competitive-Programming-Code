#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int color[100010];
void dfs(int u, int c=1){   //bipartite
    if(color[u]){
        return;
    }
    color[u]=c;
    for(auto v:G[u]){
        dfs(v, c*-1);
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(1);

    for(int i=0;i<q;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        if(color[c]!=color[d]){
            printf("Road\n");
        }else{
            printf("Town\n");
        }
    }
    return 0;
}