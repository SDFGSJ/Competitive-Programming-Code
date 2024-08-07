#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[100010];
int level[100010];
int dfs(int u,int parent = -1){
    if(level[u]!=-1){
        return level[u];
    }

    int result=-1;
    for(auto v:Tree[u]){
        if(v!=parent){
            result=max(result, dfs(v,u));
        }
    }
    level[u]=result+1;
    return level[u];
}
int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Tree[a].emplace_back(b);
        Tree[b].emplace_back(a);
    }

    for(int i=1;i<=n;i++){
        level[i]=-1;
    }
    dfs(t);
    for(int i=1;i<=n;i++){
        printf("%d ",level[i]);
    }
    printf("\n");
    return 0;
}