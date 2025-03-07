#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> G[400010];    //<v,cost>
deque<int> dq;
int dist[400010];   //dist[i] = the min dist to from vertex 1 to i
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        if(a){
            G[u].emplace_back(v,1);
            G[v].emplace_back(u,1);
        }else{
            G[n+u].emplace_back(n+v,1);
            G[n+v].emplace_back(n+u,1);
        }
    }
    for(int i=0;i<k;i++){
        int s;
        scanf("%d",&s);
        G[s].emplace_back(n+s,0);
        G[n+s].emplace_back(s,0);
    }

    for(int i=1;i<=2*n;i++){
        dist[i]=INT_MAX;
    }

    dq.emplace_back(1);   //start from (vertex, initially passable) = (1,1), whose corresponding vertex idx is 1
    dist[1]=0;
    while(!dq.empty()){
        auto now=dq.front();dq.pop_front();
        for(auto [nxt,cost]:G[now]){
            if(dist[nxt]==INT_MAX){
                dist[nxt]=dist[now]+cost;
                if(cost){
                    dq.emplace_back(nxt);
                }else{
                    dq.emplace_front(nxt);
                }
            }
        }
    }
    int ans=min(dist[n], dist[2*n]);
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
01-bfs
notice the definition of state and assign correct idx(=1) to starting state
Editorial video watched
*/