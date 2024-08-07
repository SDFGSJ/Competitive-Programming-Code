#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector<pair<int,int>> G[100010];
vector<long long> dijkstra(int n, int S) {
    vector<long long> d(n+1, INF);
    using QueuePair = pair<long long, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
    d[S] = 0; // starting point set to 0
    Q.emplace(d[S], S);
    while (Q.size()) {
        auto [u_dis, u] = Q.top();
        Q.pop();
        if (d[u] < u_dis) continue;
        for (auto [v, cost] : G[u])
            if (d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                Q.emplace(d[v], v);
            }
    }
    return d;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }
    vector<long long> dist=dijkstra(n,1);
    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            printf("-1\n");
        }else{
            printf("%lld\n",dist[i]);
        }
    }
    return 0;
}