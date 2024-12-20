#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
bool vis[200010];
int dist[200010];
int ways[200010];
int n;
const int mod=1e9+7;
void shortest_path(int s){
    for(int i=1;i<=n;i++){
        dist[i]=-1;
    }

    queue<int> q;
    q.emplace(s);
    dist[s]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(auto next:G[now]){
            if(dist[next]==-1){
                dist[next]=dist[now]+1;
                q.emplace(next);
            }
        }
    }
}
void num_of_ways(int s){
    queue<int> q;
    q.emplace(s);
    ways[s]=1;
    while(!q.empty()){
        int now=q.front();q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=true;
        for(auto next:G[now]){
            if(dist[next]==dist[now]+1){    //the predecessor of next is now(next is come from now, now => next)
                ways[next]+=ways[now];
                ways[next]%=mod;
                q.emplace(next);
            }
        }
    }
}

int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    shortest_path(1);
    num_of_ways(1);

    printf("%d\n",ways[n]);
    return 0;
}
/*
bfs 2 times
dist[i] = shortest path length from 1 to i
ways[i] = # of ways to go to node i
1st bfs to find the shortest path
2nd bfs to find # of ways to go to node n
when going from node u to v(u => v), and we have dist[v] == dist[u]+1
    ways[v]+=ways[u]

Note. Editorial use bfs 1 time
*/