#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
bool visited[100010];
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
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            printf("The graph is not connected.\n");
            return 0;
        }
    }
    printf("The graph is connected.\n");
    return 0;
}