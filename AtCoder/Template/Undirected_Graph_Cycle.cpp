bool dfs(int u,int parent){
    vis[u]=true;
    for(auto v:G[u]){
        if(v!=parent){
            if(vis[v]){
                return true;
            }else{
                if(dfs(v,u)){
                    return true;
                }
            }
        }
    }
    return false;
}