#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> G[100010];  //<v,cost>
vector<long long> dijkstra(int n, int S) {
    vector<long long> d(n+1, INT_MAX);
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

    vector<long long> distfrom1=dijkstra(n,1),distfromN=dijkstra(n,n);
    for(int k=1;k<=n;k++){
        printf("%lld\n",distfrom1[k]+distfromN[k]);   //1->k + k->N
    }
    return 0;
}
/*
dijkstra
1->k->N can be viewed as 1->k + k->N, so we can do dijkstra starting from 1 and N
then the ans would be dist(1,k)+dist(N,k)
*/