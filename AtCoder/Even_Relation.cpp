#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> Tree[100010];   //<v,weight>
long long dist[100010];
void dfs(int u,int parent){
    for(auto [v,w]:Tree[u]){
        if(v!=parent){
            dist[v]=dist[u]+w;
            dfs(v,u);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;long long w;
        scanf("%d%d%lld",&u,&v,&w);
        Tree[u].emplace_back(v,w);
        Tree[v].emplace_back(u,w);
    }

    dfs(1,-1);
    for(int i=1;i<=n;i++){
        if(dist[1]%2 == dist[i]%2){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
    return 0;
}
/*
dfs
dist[i] = dist from 1 to i
by observation, if dist[i] has same parity with dist[1], then node i has the same color with node 1
idea same as editorial
*/