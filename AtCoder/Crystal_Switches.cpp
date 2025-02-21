#include<bits/stdc++.h>
using namespace std;
vector<int> G[2][200010];
bool has_switch[200010];    //has_switch[i] = true if vertex i has switch on it
queue<tuple<int,int,int>> q;    //<vertex,step,mode>
int dist[200010][2];    //dist[i][j] = the min dist to from vertex 1 to i under mode j
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        G[a][u].emplace_back(v);
        G[a][v].emplace_back(u);
    }
    for(int i=0;i<k;i++){
        int s;
        scanf("%d",&s);
        has_switch[s]=true;
    }

    for(int i=1;i<=n;i++){
        dist[i][0]=dist[i][1]=INT_MAX;
    }

    q.emplace(1,0,1);
    dist[1][1]=0;
    while(!q.empty()){
        auto [vertex,step,mode]=q.front();q.pop();
        for(auto nxt:G[mode][vertex]){
            if(step+1 < dist[nxt][mode]){   //dist[nxt][mode]==INT_MAX
                q.emplace(nxt,step+1,mode);
                dist[nxt][mode]=step+1;
            }
        }
        if(has_switch[vertex] && step<dist[vertex][!mode]){ //dist[vertex][!mode]==INT_MAX
            q.emplace(vertex,step,!mode);
            dist[vertex][!mode]=step;
        }
    }
    int ans=min(dist[n][0], dist[n][1]);
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
bfs
dist[i][0/1] be the min dist to vertex I under mode 0/1
where mode 0 means we can only go through initially impassable edges
video watched
*/