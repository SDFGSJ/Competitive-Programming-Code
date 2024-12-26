#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> T[100010];    //<v,cost>
long long dist[100010];
void dfs(int u,int parent){
    for(auto [v,cost]:T[u]){
        if(v!=parent){
            dist[v]=dist[u]+cost;
            dfs(v,u);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        T[a].emplace_back(b,c);
        T[b].emplace_back(a,c);
    }

    int q,k;
    scanf("%d%d",&q,&k);
    dist[k]=0;
    dfs(k,-1);

    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",dist[x]+dist[y]);
    }
    return 0;
}
/*
dist[i] = shortest path length from k to i
dfs or bfs to find the shortest path from k to other vectices, view k as root
ans = dist[x]+dist[y]
*/