#include<bits/stdc++.h>
using namespace std;
int dist[200010];
vector<int> G[200010];
int ans=INT_MAX;
void bfs(int start){
    queue<int> q;
    q.emplace(start);
    dist[start]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(auto next:G[now]){
            if(next==1){    //meet the shortest cycle
                ans=min(ans,dist[now]+1);
                return;
            }
            if(dist[next]==-1){ //next not yet visited
                dist[next]=dist[now]+1;
                q.emplace(next);
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
    }

    for(int i=1;i<=n;i++){
        dist[i]=-1;
    }

    bfs(1);
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
dfs won't work at testcase like
6 7
1 2
2 3
3 4
4 5
5 1
1 6
6 5
*/