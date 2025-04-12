#include<bits/stdc++.h>
using namespace std;
tuple<int,int,long long> edges[200010];   //<u,v,t>
long long dist[405][405];
long long all_permu(vector<int>& bridges,int n){
    int k=bridges.size();

    long long bridge_cost=0;
    for(auto idx:bridges){
        auto [_,__,cost]=edges[idx];
        bridge_cost+=cost;
    }

    long long res=LONG_LONG_MAX;
    do{
        for(int mask=0;mask<(1<<k);mask++){ //bit = 0 means no flip
            vector<int> endpoints;
            for(int i=0;i<k;i++){
                auto [u,v,cost]=edges[bridges[i]];
                if((mask>>i)&1){    //flip, v -> u
                    endpoints.emplace_back(v);
                    endpoints.emplace_back(u);
                }else{  //no flip, u -> v
                    endpoints.emplace_back(u);
                    endpoints.emplace_back(v);
                }
            }

            int sz=endpoints.size();
            long long cost=0;
            cost+=dist[1][endpoints[0]];
            for(int i=0;i+1<sz;i++){
                if(i%2==0){ //walk on designated bridge

                }else{  //walk from endpoint of a bridge to endpoint of another bridge
                    int u=endpoints[i], v=endpoints[i+1];
                    cost+=dist[u][v];
                }
            }
            cost+=dist[endpoints[sz-1]][n];
            res=min(res,cost);
        }
    }while(next_permutation(bridges.begin(),bridges.end()));
    return res+bridge_cost;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }else{
                dist[i][j]=1e18;
            }
        }
    }

    for(int i=1;i<=m;i++){
        int u,v;
        long long t;
        scanf("%d%d%lld",&u,&v,&t);
        dist[u][v]=dist[v][u]=min(dist[u][v],t);
        edges[i]={u,v,t};
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        vector<int> bridge;
        for(int i=0;i<k;i++){
            int b;
            scanf("%d",&b);
            bridge.emplace_back(b);
        }
        long long res=all_permu(bridge,n);
        printf("%lld\n",res);
    }
    return 0;
}
/*
floyd warshall
if there are multi edges between u,v, pick the one with the smallest cost to do floyd warshall
enumerate all situations of crossing those bridges and find the min sum
there are k! ways of crossing order, 2^k ways to cross a bridge(which endpoint to enter?)
ex. suppose we have 2 bridges (a,b), (c,d)
then we only need to enumerate the following 2! * 2^2 = 8 cases
1->(a,b)->(c,d)->N
1->(a,b)->(d,c)->N
1->(b,a)->(c,d)->N
1->(b,a)->(d,c)->N

1->(c,d)->(a,b)->N
1->(c,d)->(b,a)->N
1->(d,c)->(a,b)->N
1->(d,c)->(b,a)->N
Editorial video watched
*/