#include<bits/stdc++.h>
using namespace std;
vector<int> G[55];
int a[55],b[55];
bool vis[55];
int n;
void bfs(int i){
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    queue<int> q;
    q.emplace(1);
    while(!q.empty()){
        int now=q.front();q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=true;
        for(auto next:G[now]){
            if((a[i]==now && b[i]==next) || (a[i]==next && b[i]==now)){
                continue;
            }
            q.emplace(next);
        }
    }
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a[i],&b[i]);
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }

    int ans=0;
    for(int i=0;i<m;i++){   //remove each edge
        bfs(i);
        for(int j=1;j<=n;j++){
            if(!vis[j]){    //if there exists some unvisited nodes after bfs => unconnected => (a[i],b[i]) is a bridge
                ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
for each edge, do bfs w/o this edge and check whether # of compo = 1(no unvisited node after 1 bfs traversal)
*/