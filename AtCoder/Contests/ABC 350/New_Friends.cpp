#include<bits/stdc++.h>
using namespace std;
vector<int> g[200010];
bool visited[200010];
pair<long long,long long> bfs(int u){
    long long cnt=1,deg=0;
    queue<int> q;
    q.emplace(u);
    visited[u]=true;
    deg+=g[u].size();
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:g[u]){
            if(!visited[v]){
                visited[v]=true;
                q.emplace(v);
                deg+=g[v].size();
                cnt++;
            }
        }
    }
    return {cnt,deg/2};
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            auto [cnt,edge]=bfs(i);
            ans+=cnt*(cnt-1)/2-edge;
        }
    }
    printf("%lld\n",ans);
    return 0;
}