#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010],rG[200010];
long long dist[200010][2];  //dist[i][0/1] = min dist from 1 to i when walking on G/rG
priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> q;  //<cost,vertex,mode>
int main(){
    int n,m;
    long long x;
    scanf("%d%d%lld",&n,&m,&x);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }

    for(int i=1;i<=n;i++){
        dist[i][0]=dist[i][1]=LONG_LONG_MAX;
    }

    q.emplace(0,1,0);
    q.emplace(x,1,1);
    /*dist[1][0]=0;
    dist[1][1]=x;*/
    while(!q.empty()){
        auto [cost,now,mode]=q.top();q.pop();
        if(dist[now][mode]!=LONG_LONG_MAX){ //visited before
            continue;
        }
        dist[now][mode]=cost;   //assign it later
        //printf("dist[%d][%d]=%lld\n",now,mode,dist[now][mode]);
        if(mode){   //walking on rG
            for(auto next:rG[now]){
                //if(dist[next][mode]==LONG_LONG_MAX){
                    //dist[next][mode]=cost+1;
                    q.emplace(cost+1,next,mode);
                //}
            }
            for(auto next:G[now]){
                //if(dist[next][!mode]==LONG_LONG_MAX){
                    //dist[next][!mode]=cost+x+1;
                    q.emplace(cost+x+1,next,!mode);
                //}
            }
        }else{  //walking on G
            for(auto next:G[now]){
                //if(dist[next][mode]==LONG_LONG_MAX){
                    //dist[next][mode]=cost+1;
                    q.emplace(cost+1,next,mode);
                //}
            }
            for(auto next:rG[now]){
                //if(dist[next][!mode]==LONG_LONG_MAX){
                    //dist[next][!mode]=cost+x+1;
                    q.emplace(cost+x+1,next,!mode);
                //}
            }
        }
    }
    printf("%lld\n",min(dist[n][0], dist[n][1]));
    return 0;
}
/*
Editorial article,video: Dijkstra
*/