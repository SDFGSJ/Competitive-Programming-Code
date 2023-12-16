#include<bits/stdc++.h>
using namespace std;
vector<int> g[300010];
bool visited[300010];
int mymax=-1,component;
int bfs(int now){
    component++;
    int cnt=1;
    queue<int> q;
    q.push(now);
    visited[now]=true;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto next:g[u]){
            if(!visited[next]){
                q.emplace(next);
                visited[next]=true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==1 || v==1){
            continue;
        }
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=2;i<=n;i++){
        if(!visited[i]){
            mymax=max(mymax,bfs(i));
        }
    }
    if(component==1){
        printf("1\n");
    }else{
        printf("%d\n",n-mymax);
    }
    return 0;
}