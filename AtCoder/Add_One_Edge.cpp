#include<bits/stdc++.h>
using namespace std;
vector<int> G[300010];
int dist[300010];
bool visited[300010];
int bfs(int start){
    int min_dist=0;
    queue<int> q;
    dist[start]=0;
    q.emplace(start);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto v:G[u]){
            dist[v]=min(dist[v],dist[u]+1);
            min_dist=max(min_dist,dist[v]);
            q.emplace(v);
        }
    }
    return min_dist;
}
int main(){
    int n1,n2,m;
    scanf("%d%d%d",&n1,&n2,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for(int i=1;i<=n1+n2;i++){
        dist[i]=INT_MAX;
    }
    int dist1=bfs(1);
    int dist2=bfs(n1+n2);
    printf("%d\n",dist1+dist2+1);
    return 0;
}