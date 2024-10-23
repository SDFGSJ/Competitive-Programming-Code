#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int dist[100010],prede[100010];
bool vis[100010];
queue<int> q;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    q.emplace(1);
    while(!q.empty()){
        int now=q.front();q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=true;
        for(auto next:G[now]){
            if(prede[next]==0){
                prede[next]=now;
            }
            q.emplace(next);
        }
    }

    bool haveans=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            haveans=false;
            break;
        }
    }

    if(haveans){
        printf("Yes\n");
        for(int i=2;i<=n;i++){
            printf("%d\n",prede[i]);
        }
    }else{
        printf("No\n");
    }
    return 0;
}