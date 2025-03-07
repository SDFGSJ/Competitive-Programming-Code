#include<bits/stdc++.h>
using namespace std;
vector<int> G[15];
int dist[15];
int bfs(int s,int n){
    for(int i=1;i<=n;i++){
        dist[i]=-1;
    }

    queue<int> q;
    q.emplace(s);
    dist[s]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(auto next:G[now]){
            if(dist[next]==-1){
                dist[next]=dist[now]+1;
                q.emplace(next);
            }
        }
    }

    int res=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==2){
            res++;
        }
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int start=1;start<=n;start++){
        int cnt=bfs(start,n);
        printf("%d\n",cnt);
    }
    return 0;
}
/*
bfs
friend of friend of node s = any node whose dist to s is 2
*/