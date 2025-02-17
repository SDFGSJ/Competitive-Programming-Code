#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> G[200010];    //<v,cost,id>
int idx[200010];
vector<long long> dijkstra(int n, int S) {
    vector<long long> d(n+1, LONG_LONG_MAX);
    using QueuePair = pair<long long, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
    d[S] = 0; // starting point set to 0
    Q.emplace(d[S], S);
    while (Q.size()) {
        auto [u_dis, u] = Q.top();
        Q.pop();
        if (d[u] < u_dis) continue;
        for (auto [v, cost, id] : G[u])
            if (d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                Q.emplace(d[v], v);
                idx[v]=id;
            }
    }
    return d;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].emplace_back(b,c,i);
    }

    dijkstra(n,1);
    for(int i=2;i<=n;i++){
        printf("%d ",idx[i]);
    }
    printf("\n");
    return 0;
}
/*
dijkstra?

mst failed on cases like:
3 3
1 2 3
1 3 2
2 3 2
*/