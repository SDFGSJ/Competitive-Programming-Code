#include<bits/stdc++.h>
using namespace std;
vector<int> adj[2005];
bool visited[2005];
int bfs(int i){
    int cnt=0;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        cnt++;
        for(auto v:adj[u]){
            q.emplace(v);
        }
    }
    return cnt;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].emplace_back(b);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            visited[j]=false;
        }
        ans+=bfs(i);
    }
    printf("%d\n",ans);
    return 0;
}