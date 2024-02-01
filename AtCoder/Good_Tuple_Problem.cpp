#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
set<int> G[200010];
int color[200010];
bool visited[200010];
bool dfs(int u,int c=1){
    if(color[u]){
        return color[u]==c;
    }
    visited[u]=true;
    color[u]=c;
    for(auto v:G[u]){
        if(!dfs(v, c*-1)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<m;i++){
        G[a[i]].emplace(b[i]);
        G[b[i]].emplace(a[i]);
    }

    bool ok=true;
    for(int i=1;i<=n;i++){  //the graph might not be connected, and the index might not start from 1
        if(!visited[i]){
            visited[i]=true;
            ok&=dfs(i);
        }
    }

    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}