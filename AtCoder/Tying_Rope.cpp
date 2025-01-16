#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
bool vis[200010];
bool dfs(int u,int parent){
    if(vis[u]){
        return true;
    }
    vis[u]=true;
    int edge_to_parent=0;   //# of edges to parent
    for(auto v:G[u]){
        if(v!=parent){
            if(dfs(v,u)){
                return true;
            }
        }else{
            edge_to_parent++;
        }
    }
    if(edge_to_parent>=2){  //multi edges to parent => contains cycle
        return true;
    }
    return false;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,c;char b,d;
        scanf("%d %c %d %c",&a,&b,&c,&d);
        G[a].emplace_back(c);
        G[c].emplace_back(a);
    }

    int compo=0,cycle=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            compo++;
            cycle+=dfs(i,-1);
        }
    }
    printf("%d %d\n",cycle,compo-cycle);
    return 0;
}
/*
dfs detect cycle
we can view a rope as a node, 2 ends of the rope as the undirected outgoing edges from node
add undirected edges for each Ai,Ci
when doing dfs, if there are multi edges to parent, then it contains cycles
*/