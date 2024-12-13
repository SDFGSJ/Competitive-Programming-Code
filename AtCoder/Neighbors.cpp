#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int color[100010];  //white=0, gray=1, black=2
int deg[100010];
bool hascycle=false,isans=true;
void dfs(int u,int parent){
    color[u]=1;
    if(deg[u]>2){
        isans=false;
    }
    for(auto v:G[u]){
        if(v==parent){
            continue;
        }
        if(!color[v]){
            dfs(v,u);
        }else if(color[v]==1){
            hascycle=true;
        }
    }
    color[u]=2;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        deg[a]++,deg[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!color[i]){
            dfs(i,0);
        }
    }

    if(!isans || hascycle){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}
/*
deg[i] = vertex i's degree
use dfs to detect cycles in undirected graph
maintain the degree of every vertex, if there exists a node whose deg>=3, then the ans is No
if there's a cycle in the graph, it means that they couldn't line up in a row, the ans is also No
*/