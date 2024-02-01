#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
bool visited[200010];
bool bfs(int i){
    vector<int> vertex;
    queue<int> q;
    q.emplace(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(visited[u]){
            continue;
        }
        vertex.emplace_back(u);
        visited[u]=true;
        for(auto v:G[u]){
            q.emplace(v);
        }
    }

    int edges=0;    //degree
    for(auto v:vertex){
        edges+=G[v].size();
    }
    return vertex.size() == edges/2;    // |V| == deg/2
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

    bool ok=true;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ok&=bfs(i);
        }
    }
    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}