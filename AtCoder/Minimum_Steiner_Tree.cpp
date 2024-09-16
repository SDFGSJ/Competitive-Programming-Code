#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[200010];
int v[200010],prede[200010];
bool visited[200010],included[200010];
void dfs(int u,int parent){
    if(visited[u]){
        return;
    }
    visited[u]=true;
    for(auto v:Tree[u]){
        if(v!=parent){
            prede[v]=u;
            dfs(v,u);
        }
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Tree[a].emplace_back(b);
        Tree[b].emplace_back(a);
    }
    for(int i=0;i<k;i++){
        scanf("%d",&v[i]);
    }

    int root=v[0];  //pick 1 node as the root from the k specified vertices
    dfs(root,0);    //perform dfs on that root to get predecessors

    included[v[0]]=true;    //add root into ans
    for(int i=1;i<k;i++){   //for other node, trace back to root
        int now=v[i];
        while(!included[now]){  //if met an included node, it means you're from a smaller branch
            included[now]=true;
            now=prede[now];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(included[i]){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
using dfs and predecessors to construct a tree that includes k specified vertices
*/