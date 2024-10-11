#include<bits/stdc++.h>
using namespace std;
long long v_cost[200010];
vector<pair<int,long long>> G[200010];  //<v,edgecost>
vector<long long> dijkstra(int n, int S) {  //modified
    vector<long long> d(n+1, LONG_LONG_MAX);
    using QueuePair = pair<long long, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
    d[S] = 0; // starting point set to 0
    Q.emplace(d[S], S);
    while (Q.size()) {
        auto [u_dis, u] = Q.top();
        Q.pop();
        if (d[u] < u_dis) continue;
        for (auto [v, e_cost] : G[u])
            if (d[v] > d[u] + e_cost + v_cost[v]) {
                d[v] = d[u] + e_cost + v_cost[v];
                Q.emplace(d[v], v);
            }
    }
    return d;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v_cost[i]);
    }
    for(int i=0;i<m;i++){
        int u,v;
        long long b;
        scanf("%d%d%lld",&u,&v,&b);
        G[u].emplace_back(v,b);
        G[v].emplace_back(u,b);
    }
    vector<long long> ans=dijkstra(n,1);
    for(int i=2;i<=n;i++){
        printf("%lld ",ans[i]+v_cost[1]);
    }
    printf("\n");
    return 0;
}