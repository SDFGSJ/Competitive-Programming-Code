#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int dist[100010];
bool visited[100010];
queue<int> q;
void bfs(int start){
    q.emplace(start);
    dist[start]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        if(visited[now]){
            continue;
        }
        visited[now]=true;
        for(auto next:G[now]){
            dist[next]=min(dist[next], dist[now]+1);
            q.emplace(next);
        }
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

    for(int i=1;i<=n;i++){
        dist[i]=1e9;
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9){
            printf("-1\n");
        }else{
            printf("%d\n",dist[i]);
        }
    }
    return 0;
}