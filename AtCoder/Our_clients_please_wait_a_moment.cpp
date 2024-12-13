#include<bits/stdc++.h>
using namespace std;
long long D[1005][1005];
int a,b,c;
vector<long long> dijkstra(int n, int S, bool bycar) {
    vector<long long> d(n+1, 1e18);
    using QueuePair = pair<long long, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
    d[S] = 0; // starting point set to 0
    Q.emplace(d[S], S);
    while (Q.size()) {
        auto [u_dis, u] = Q.top();
        Q.pop();
        if (d[u] < u_dis) continue;
        for(int v=0;v<n;v++){
            long long cost=0;
            if(bycar){
                cost=D[u][v]*a;
            }else{
                cost=D[u][v]*b+c;
            }
            if(d[v] > d[u]+cost){
                d[v]=d[u]+cost;
                Q.emplace(d[v],v);
            }
        }
    }
    return d;
}
int main(){
    int n;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&D[i][j]);
        }
    }

    vector<long long> car=dijkstra(n,0,true), train=dijkstra(n,n-1,false);
    long long ans=LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,car[i]+train[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
car[i] = cost from 0 to i by company car
train[i] = cost from n-1 to i by train
do dijkstra 2 times
1 to others by company car & n to others by train
enumerate all possible cities where he switch from car to train
ans is min{0 to i by car + i to n-1 by train} i=0~n-1
*/